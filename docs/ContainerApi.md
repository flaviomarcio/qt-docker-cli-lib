# ContainerApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**containerArchive**](ContainerApi.md#containerArchive) | **GET** /containers/{id}/archive | Get an archive of a filesystem resource in a container
[**containerArchiveInfo**](ContainerApi.md#containerArchiveInfo) | **HEAD** /containers/{id}/archive | Get information about files in a container
[**containerAttach**](ContainerApi.md#containerAttach) | **POST** /containers/{id}/attach | Attach to a container
[**containerAttachWebsocket**](ContainerApi.md#containerAttachWebsocket) | **GET** /containers/{id}/attach/ws | Attach to a container via a websocket
[**containerChanges**](ContainerApi.md#containerChanges) | **GET** /containers/{id}/changes | Get changes on a container’s filesystem
[**containerCreate**](ContainerApi.md#containerCreate) | **POST** /containers/create | Create a container
[**containerDelete**](ContainerApi.md#containerDelete) | **DELETE** /containers/{id} | Remove a container
[**containerExport**](ContainerApi.md#containerExport) | **GET** /containers/{id}/export | Export a container
[**containerInspect**](ContainerApi.md#containerInspect) | **GET** /containers/{id}/json | Inspect a container
[**containerKill**](ContainerApi.md#containerKill) | **POST** /containers/{id}/kill | Kill a container
[**containerList**](ContainerApi.md#containerList) | **GET** /containers/json | List containers
[**containerLogs**](ContainerApi.md#containerLogs) | **GET** /containers/{id}/logs | Get container logs
[**containerPause**](ContainerApi.md#containerPause) | **POST** /containers/{id}/pause | Pause a container
[**containerPrune**](ContainerApi.md#containerPrune) | **POST** /containers/prune | Delete stopped containers
[**containerRename**](ContainerApi.md#containerRename) | **POST** /containers/{id}/rename | Rename a container
[**containerResize**](ContainerApi.md#containerResize) | **POST** /containers/{id}/resize | Resize a container TTY
[**containerRestart**](ContainerApi.md#containerRestart) | **POST** /containers/{id}/restart | Restart a container
[**containerStart**](ContainerApi.md#containerStart) | **POST** /containers/{id}/start | Start a container
[**containerStats**](ContainerApi.md#containerStats) | **GET** /containers/{id}/stats | Get container stats based on resource usage
[**containerStop**](ContainerApi.md#containerStop) | **POST** /containers/{id}/stop | Stop a container
[**containerTop**](ContainerApi.md#containerTop) | **GET** /containers/{id}/top | List processes running inside a container
[**containerUnpause**](ContainerApi.md#containerUnpause) | **POST** /containers/{id}/unpause | Unpause a container
[**containerUpdate**](ContainerApi.md#containerUpdate) | **POST** /containers/{id}/update | Update a container
[**containerWait**](ContainerApi.md#containerWait) | **POST** /containers/{id}/wait | Wait for a container
[**putContainerArchive**](ContainerApi.md#putContainerArchive) | **PUT** /containers/{id}/archive | Extract an archive of files or folders to a directory in a container


## **containerArchive**

Get an archive of a filesystem resource in a container

Get a tar archive of a resource in the filesystem of container id.

### Example
```bash
 containerArchive id=value  path=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **path** | **string** | Resource in the container’s filesystem to archive. |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/x-tar

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerArchiveInfo**

Get information about files in a container

A response header 'X-Docker-Container-Path-Stat' is returned, containing
a base64 - encoded JSON object with some filesystem header information
about the path.

### Example
```bash
 containerArchiveInfo id=value  path=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **path** | **string** | Resource in the container’s filesystem to archive. |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerAttach**

Attach to a container

Attach to a container to read its output or send it input. You can attach
to the same container multiple times and you can reattach to containers
that have been detached.

Either the 'stream' or 'logs' parameter must be 'true' for this endpoint
to do anything.

See the [documentation for the 'docker attach' command](https://docs.docker.com/engine/reference/commandline/attach/)
for more details.

### Hijacking

This endpoint hijacks the HTTP connection to transport 'stdin', 'stdout',
and 'stderr' on the same socket.

This is the response from the daemon for an attach request:

'''
HTTP/1.1 200 OK
Content-Type: application/vnd.docker.raw-stream

[STREAM]
'''

After the headers and two new lines, the TCP connection can now be used
for raw, bidirectional communication between the client and server.

To hint potential proxies about connection hijacking, the Docker client
can also optionally send connection upgrade headers.

For example, the client sends this request to upgrade the connection:

'''
POST /containers/16253994b7c4/attach?stream=1&stdout=1 HTTP/1.1
Upgrade: tcp
Connection: Upgrade
'''

The Docker daemon will respond with a '101 UPGRADED' response, and will
similarly follow with the raw stream:

'''
HTTP/1.1 101 UPGRADED
Content-Type: application/vnd.docker.raw-stream
Connection: Upgrade
Upgrade: tcp

[STREAM]
'''

### Stream format

When the TTY setting is disabled in ['POST /containers/create'](#operation/ContainerCreate),
the HTTP Content-Type header is set to application/vnd.docker.multiplexed-stream
and the stream over the hijacked connected is multiplexed to separate out
'stdout' and 'stderr'. The stream consists of a series of frames, each
containing a header and a payload.

The header contains the information which the stream writes ('stdout' or
'stderr'). It also contains the size of the associated frame encoded in
the last four bytes ('uint32').

It is encoded on the first eight bytes like this:

'''go
header := [8]byte{STREAM_TYPE, 0, 0, 0, SIZE1, SIZE2, SIZE3, SIZE4}
'''

'STREAM_TYPE' can be:

- 0: 'stdin' (is written on 'stdout')
- 1: 'stdout'
- 2: 'stderr'

'SIZE1, SIZE2, SIZE3, SIZE4' are the four bytes of the 'uint32' size
encoded as big endian.

Following the header is the payload, which is the specified number of
bytes of 'STREAM_TYPE'.

The simplest way to implement this protocol is the following:

1. Read 8 bytes.
2. Choose 'stdout' or 'stderr' depending on the first byte.
3. Extract the frame size from the last four bytes.
4. Read the extracted size and output it on the correct output.
5. Goto 1.

### Stream format when using a TTY

When the TTY setting is enabled in ['POST /containers/create'](#operation/ContainerCreate),
the stream is not multiplexed. The data exchanged over the hijacked
connection is simply the raw data from the process PTY and client's
'stdin'.

### Example
```bash
 containerAttach id=value  detachKeys=value  logs=value  stream=value  stdin=value  stdout=value  stderr=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **detachKeys** | **string** | Override the key sequence for detaching a container.Format is a single
character '[a-Z]' or 'ctrl-<value>' where '<value>' is one of: 'a-z',
'@', '^', '[', ',' or '_'. | [optional]
 **logs** | **boolean** | Replay previous logs from the container.

This is useful for attaching to a container that has started and you
want to output everything since the container started.

If 'stream' is also enabled, once all the previous output has been
returned, it will seamlessly transition into streaming current
output. | [optional] [default to false]
 **stream** | **boolean** | Stream attached streams from the time the request was made onwards. | [optional] [default to false]
 **stdin** | **boolean** | Attach to 'stdin' | [optional] [default to false]
 **stdout** | **boolean** | Attach to 'stdout' | [optional] [default to false]
 **stderr** | **boolean** | Attach to 'stderr' | [optional] [default to false]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/vnd.docker.raw-stream, application/vnd.docker.multiplexed-stream

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerAttachWebsocket**

Attach to a container via a websocket

### Example
```bash
 containerAttachWebsocket id=value  detachKeys=value  logs=value  stream=value  stdin=value  stdout=value  stderr=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **detachKeys** | **string** | Override the key sequence for detaching a container.Format is a single
character '[a-Z]' or 'ctrl-<value>' where '<value>' is one of: 'a-z',
'@', '^', '[', ',', or '_'. | [optional]
 **logs** | **boolean** | Return logs | [optional] [default to false]
 **stream** | **boolean** | Return stream | [optional] [default to false]
 **stdin** | **boolean** | Attach to 'stdin' | [optional] [default to false]
 **stdout** | **boolean** | Attach to 'stdout' | [optional] [default to false]
 **stderr** | **boolean** | Attach to 'stderr' | [optional] [default to false]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerChanges**

Get changes on a container’s filesystem

Returns which files in a container's filesystem have been added, deleted,
or modified. The 'Kind' of modification can be one of:

- '0': Modified (\"C\")
- '1': Added (\"A\")
- '2': Deleted (\"D\")

### Example
```bash
 containerChanges id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |

### Return type

[**array[FilesystemChange]**](FilesystemChange.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerCreate**

Create a container

### Example
```bash
 containerCreate  name=value  platform=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**object**](.md) | Container to create |
 **name** | **string** | Assign the specified name to the container. Must match
'/?[a-zA-Z0-9][a-zA-Z0-9_.-]+'. | [optional]
 **platform** | **string** | Platform in the format 'os[/arch[/variant]]' used for image lookup.

When specified, the daemon checks if the requested image is present
in the local image cache with the given OS and Architecture, and
otherwise returns a '404' status.

If the option is not set, the host's native OS and Architecture are
used to look up the image in the image cache. However, if no platform
is passed and the given image does exist in the local image cache,
but its OS or architecture does not match, the container is created
with the available image, and a warning is added to the 'Warnings'
field in the response, for example;

    WARNING: The requested image's platform (linux/arm64/v8) does not
             match the detected host platform (linux/amd64) and no
             specific platform was requested | [optional] [default to ]

### Return type

[**ContainerCreateResponse**](ContainerCreateResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerDelete**

Remove a container

### Example
```bash
 containerDelete id=value  v=value  force=value  link=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **v** | **boolean** | Remove anonymous volumes associated with the container. | [optional] [default to false]
 **force** | **boolean** | If the container is running, kill it before removing it. | [optional] [default to false]
 **link** | **boolean** | Remove the specified link associated with the container. | [optional] [default to false]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerExport**

Export a container

Export the contents of a container as a tarball.

### Example
```bash
 containerExport id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/octet-stream

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerInspect**

Inspect a container

Return low-level information about a container.

### Example
```bash
 containerInspect id=value  size=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **size** | **boolean** | Return the size of container as fields 'SizeRw' and 'SizeRootFs' | [optional] [default to false]

### Return type

[**ContainerInspectResponse**](ContainerInspectResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerKill**

Kill a container

Send a POSIX signal to a container, defaulting to killing to the
container.

### Example
```bash
 containerKill id=value  signal=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **signal** | **string** | Signal to send to the container as an integer or string (e.g. 'SIGINT'). | [optional] [default to SIGKILL]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerList**

List containers

Returns a list of containers. For details on the format, see the
[inspect endpoint](#operation/ContainerInspect).

Note that it uses a different, smaller representation of a container
than inspecting a single container. For example, the list of linked
containers is not propagated .

### Example
```bash
 containerList  all=value  limit=value  size=value  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **all** | **boolean** | Return all containers. By default, only running containers are shown. | [optional] [default to false]
 **limit** | **integer** | Return this number of most recently created containers, including
non-running ones. | [optional]
 **size** | **boolean** | Return the size of container as fields 'SizeRw' and 'SizeRootFs'. | [optional] [default to false]
 **filters** | **string** | Filters to process on the container list, encoded as JSON (a
'map[string][]string'). For example, '{\"status\": [\"paused\"]}' will
only return paused containers.

Available filters:

- 'ancestor'=('<image-name>[:<tag>]', '<image id>', or '<image@digest>')
- 'before'=('<container id>' or '<container name>')
- 'expose'=('<port>[/<proto>]'|'<startport-endport>/[<proto>]')
- 'exited=<int>' containers with exit code of '<int>'
- 'health'=('starting'|'healthy'|'unhealthy'|'none')
- 'id=<ID>' a container's ID
- 'isolation='('default'|'process'|'hyperv') (Windows daemon only)
- 'is-task='('true'|'false')
- 'label=key' or 'label=\"key=value\"' of a container label
- 'name=<name>' a container's name
- 'network'=('<network id>' or '<network name>')
- 'publish'=('<port>[/<proto>]'|'<startport-endport>/[<proto>]')
- 'since'=('<container id>' or '<container name>')
- 'status='('created'|'restarting'|'running'|'removing'|'paused'|'exited'|'dead')
- 'volume'=('<volume name>' or '<mount point destination>') | [optional]

### Return type

[**array[ContainerSummary]**](ContainerSummary.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerLogs**

Get container logs

Get 'stdout' and 'stderr' logs from a container.

Note: This endpoint works only for containers with the 'json-file' or
'journald' logging driver.

### Example
```bash
 containerLogs id=value  follow=value  stdout=value  stderr=value  since=value  until=value  timestamps=value  tail=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **follow** | **boolean** | Keep connection after returning logs. | [optional] [default to false]
 **stdout** | **boolean** | Return logs from 'stdout' | [optional] [default to false]
 **stderr** | **boolean** | Return logs from 'stderr' | [optional] [default to false]
 **since** | **integer** | Only return logs since this time, as a UNIX timestamp | [optional] [default to 0]
 **_until** | **integer** | Only return logs before this time, as a UNIX timestamp | [optional] [default to 0]
 **timestamps** | **boolean** | Add timestamps to every log line | [optional] [default to false]
 **tail** | **string** | Only return this number of log lines from the end of the logs.
Specify as an integer or 'all' to output all log lines. | [optional] [default to all]

### Return type

**binary**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/vnd.docker.raw-stream, application/vnd.docker.multiplexed-stream

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerPause**

Pause a container

Use the freezer cgroup to suspend all processes in a container.

Traditionally, when suspending a process the 'SIGSTOP' signal is used,
which is observable by the process being suspended. With the freezer
cgroup the process is unaware, and unable to capture, that it is being
suspended, and subsequently resumed.

### Example
```bash
 containerPause id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerPrune**

Delete stopped containers

### Example
```bash
 containerPrune  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | Filters to process on the prune list, encoded as JSON (a 'map[string][]string').

Available filters:
- 'until=<timestamp>' Prune containers created before this timestamp. The '<timestamp>' can be Unix timestamps, date formatted timestamps, or Go duration strings (e.g. '10m', '1h30m') computed relative to the daemon machine’s time.
- 'label' ('label=<key>', 'label=<key>=<value>', 'label!=<key>', or 'label!=<key>=<value>') Prune containers with (or without, in case 'label!=...' is used) the specified labels. | [optional]

### Return type

[**ContainerPruneResponse**](ContainerPruneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerRename**

Rename a container

### Example
```bash
 containerRename id=value  name=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **name** | **string** | New name for the container |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerResize**

Resize a container TTY

Resize the TTY for a container.

### Example
```bash
 containerResize id=value  h=value  w=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **h** | **integer** | Height of the TTY session in characters | [optional]
 **w** | **integer** | Width of the TTY session in characters | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerRestart**

Restart a container

### Example
```bash
 containerRestart id=value  signal=value  t=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **signal** | **string** | Signal to send to the container as an integer or string (e.g. 'SIGINT'). | [optional]
 **t** | **integer** | Number of seconds to wait before killing the container | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerStart**

Start a container

### Example
```bash
 containerStart id=value  detachKeys=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **detachKeys** | **string** | Override the key sequence for detaching a container. Format is a
single character '[a-Z]' or 'ctrl-<value>' where '<value>' is one
of: 'a-z', '@', '^', '[', ',' or '_'. | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerStats**

Get container stats based on resource usage

This endpoint returns a live stream of a container’s resource usage
statistics.

The 'precpu_stats' is the CPU statistic of the *previous* read, and is
used to calculate the CPU usage percentage. It is not an exact copy
of the 'cpu_stats' field.

If either 'precpu_stats.online_cpus' or 'cpu_stats.online_cpus' is
nil then for compatibility with older daemons the length of the
corresponding 'cpu_usage.percpu_usage' array should be used.

On a cgroup v2 host, the following fields are not set
* 'blkio_stats': all fields other than 'io_service_bytes_recursive'
* 'cpu_stats': 'cpu_usage.percpu_usage'
* 'memory_stats': 'max_usage' and 'failcnt'
Also, 'memory_stats.stats' fields are incompatible with cgroup v1.

To calculate the values shown by the 'stats' command of the docker cli tool
the following formulas can be used:
* used_memory = 'memory_stats.usage - memory_stats.stats.cache'
* available_memory = 'memory_stats.limit'
* Memory usage % = '(used_memory / available_memory) * 100.0'
* cpu_delta = 'cpu_stats.cpu_usage.total_usage - precpu_stats.cpu_usage.total_usage'
* system_cpu_delta = 'cpu_stats.system_cpu_usage - precpu_stats.system_cpu_usage'
* number_cpus = 'lenght(cpu_stats.cpu_usage.percpu_usage)' or 'cpu_stats.online_cpus'
* CPU usage % = '(cpu_delta / system_cpu_delta) * number_cpus * 100.0'

### Example
```bash
 containerStats id=value  stream=value  one-shot=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **stream** | **boolean** | Stream the output. If false, the stats will be output once and then
it will disconnect. | [optional] [default to true]
 **oneShot** | **boolean** | Only get a single stat instead of waiting for 2 cycles. Must be used
with 'stream=false'. | [optional] [default to false]

### Return type

**map**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerStop**

Stop a container

### Example
```bash
 containerStop id=value  signal=value  t=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **signal** | **string** | Signal to send to the container as an integer or string (e.g. 'SIGINT'). | [optional]
 **t** | **integer** | Number of seconds to wait before killing the container | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerTop**

List processes running inside a container

On Unix systems, this is done by running the 'ps' command. This endpoint
is not supported on Windows.

### Example
```bash
 containerTop id=value  ps_args=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **psArgs** | **string** | The arguments to pass to 'ps'. For example, 'aux' | [optional] [default to -ef]

### Return type

[**ContainerTopResponse**](ContainerTopResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerUnpause**

Unpause a container

Resume a container which has been paused.

### Example
```bash
 containerUnpause id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerUpdate**

Update a container

Change various configuration options of a container without having to
recreate it.

### Example
```bash
 containerUpdate id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **update** | [**object**](.md) |  |

### Return type

[**ContainerUpdateResponse**](ContainerUpdateResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **containerWait**

Wait for a container

Block until a container stops, then returns the exit code.

### Example
```bash
 containerWait id=value  condition=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **condition** | **string** | Wait until a container state reaches the given condition.

Defaults to 'not-running' if omitted or empty. | [optional] [default to not-running]

### Return type

[**ContainerWaitResponse**](ContainerWaitResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **putContainerArchive**

Extract an archive of files or folders to a directory in a container

Upload a tar archive to be extracted to a path in the filesystem of container id.
'path' parameter is asserted to be a directory. If it exists as a file, 400 error
will be returned with message \"not a directory\".

### Example
```bash
 putContainerArchive id=value  path=value  noOverwriteDirNonDir=value  copyUIDGID=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the container |
 **path** | **string** | Path to a directory in the container to extract the archive’s contents into. |
 **inputStream** | **binary** | The input stream must be a tar archive compressed with one of the
following algorithms: 'identity' (no compression), 'gzip', 'bzip2',
or 'xz'. |
 **noOverwriteDirNonDir** | **string** | If '1', 'true', or 'True' then it will be an error if unpacking the
given content would cause an existing directory to be replaced with
a non-directory and vice versa. | [optional]
 **copyUIDGID** | **string** | If '1', 'true', then it will copy UID/GID maps to the dest file or
dir | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/x-tar, application/octet-stream
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

