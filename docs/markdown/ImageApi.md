# ImageApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**buildPrune**](ImageApi.md#buildPrune) | **POST** /build/prune | Delete builder cache
[**imageBuild**](ImageApi.md#imageBuild) | **POST** /build | Build an image
[**imageCommit**](ImageApi.md#imageCommit) | **POST** /commit | Create a new image from a container
[**imageCreate**](ImageApi.md#imageCreate) | **POST** /images/create | Create an image
[**imageDelete**](ImageApi.md#imageDelete) | **DELETE** /images/{name} | Remove an image
[**imageGet**](ImageApi.md#imageGet) | **GET** /images/{name}/get | Export an image
[**imageGetAll**](ImageApi.md#imageGetAll) | **GET** /images/get | Export several images
[**imageHistory**](ImageApi.md#imageHistory) | **GET** /images/{name}/history | Get the history of an image
[**imageInspect**](ImageApi.md#imageInspect) | **GET** /images/{name}/json | Inspect an image
[**imageList**](ImageApi.md#imageList) | **GET** /images/json | List Images
[**imageLoad**](ImageApi.md#imageLoad) | **POST** /images/load | Import images
[**imagePrune**](ImageApi.md#imagePrune) | **POST** /images/prune | Delete unused images
[**imagePush**](ImageApi.md#imagePush) | **POST** /images/{name}/push | Push an image
[**imageSearch**](ImageApi.md#imageSearch) | **GET** /images/search | Search images
[**imageTag**](ImageApi.md#imageTag) | **POST** /images/{name}/tag | Tag an image


## **buildPrune**

Delete builder cache

### Example
```bash
 buildPrune  keep-storage=value  all=value  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **keepStorage** | **integer** | Amount of disk space in bytes to keep for cache | [optional]
 **all** | **boolean** | Remove all types of build cache | [optional]
 **filters** | **string** | A JSON encoded value of the filters (a 'map[string][]string') to
process on the list of build cache objects.

Available filters:

- 'until=<timestamp>' remove cache older than '<timestamp>'. The '<timestamp>' can be Unix timestamps, date formatted timestamps, or Go duration strings (e.g. '10m', '1h30m') computed relative to the daemon's local time.
- 'id=<id>'
- 'parent=<id>'
- 'type=<string>'
- 'description=<string>'
- 'inuse'
- 'shared'
- 'private' | [optional]

### Return type

[**BuildPruneResponse**](BuildPruneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageBuild**

Build an image

Build an image from a tar archive with a 'Dockerfile' in it.

The 'Dockerfile' specifies how the image is built from the tar archive. It is typically in the archive's root, but can be at a different path or have a different name by specifying the 'dockerfile' parameter. [See the 'Dockerfile' reference for more information](https://docs.docker.com/engine/reference/builder/).

The Docker daemon performs a preliminary validation of the 'Dockerfile' before starting the build, and returns an error if the syntax is incorrect. After that, each instruction is run one-by-one until the ID of the new image is output.

The build is canceled if the client drops the connection by quitting or being killed.

### Example
```bash
 imageBuild  dockerfile=value  t=value  extrahosts=value  remote=value  q=value  nocache=value  cachefrom=value  pull=value  rm=value  forcerm=value  memory=value  memswap=value  cpushares=value  cpusetcpus=value  cpuperiod=value  cpuquota=value  buildargs=value  shmsize=value  squash=value  labels=value  networkmode=value Content-type:value X-Registry-Config:value  platform=value  target=value  outputs=value  version=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **inputStream** | **binary** | A tar archive compressed with one of the following algorithms: identity (no compression), gzip, bzip2, xz. | [optional]
 **dockerfile** | **string** | Path within the build context to the 'Dockerfile'. This is ignored if 'remote' is specified and points to an external 'Dockerfile'. | [optional] [default to Dockerfile]
 **t** | **string** | A name and optional tag to apply to the image in the 'name:tag' format. If you omit the tag the default 'latest' value is assumed. You can provide several 't' parameters. | [optional]
 **extrahosts** | **string** | Extra hosts to add to /etc/hosts | [optional]
 **remote** | **string** | A Git repository URI or HTTP/HTTPS context URI. If the URI points to a single text file, the file’s contents are placed into a file called 'Dockerfile' and the image is built from that file. If the URI points to a tarball, the file is downloaded by the daemon and the contents therein used as the context for the build. If the URI points to a tarball and the 'dockerfile' parameter is also specified, there must be a file with the corresponding path inside the tarball. | [optional]
 **q** | **boolean** | Suppress verbose build output. | [optional] [default to false]
 **nocache** | **boolean** | Do not use the cache when building the image. | [optional] [default to false]
 **cachefrom** | **string** | JSON array of images used for build cache resolution. | [optional]
 **pull** | **string** | Attempt to pull the image even if an older image exists locally. | [optional]
 **rm** | **boolean** | Remove intermediate containers after a successful build. | [optional] [default to true]
 **forcerm** | **boolean** | Always remove intermediate containers, even upon failure. | [optional] [default to false]
 **memory** | **integer** | Set memory limit for build. | [optional]
 **memswap** | **integer** | Total memory (memory + swap). Set as '-1' to disable swap. | [optional]
 **cpushares** | **integer** | CPU shares (relative weight). | [optional]
 **cpusetcpus** | **string** | CPUs in which to allow execution (e.g., '0-3', '0,1'). | [optional]
 **cpuperiod** | **integer** | The length of a CPU period in microseconds. | [optional]
 **cpuquota** | **integer** | Microseconds of CPU time that the container can get in a CPU period. | [optional]
 **buildargs** | **string** | JSON map of string pairs for build-time variables. Users pass these values at build-time. Docker uses the buildargs as the environment context for commands run via the 'Dockerfile' RUN instruction, or for variable expansion in other 'Dockerfile' instructions. This is not meant for passing secret values.

For example, the build arg 'FOO=bar' would become '{\"FOO\":\"bar\"}' in JSON. This would result in the query parameter 'buildargs={\"FOO\":\"bar\"}'. Note that '{\"FOO\":\"bar\"}' should be URI component encoded.

[Read more about the buildargs instruction.](https://docs.docker.com/engine/reference/builder/#arg) | [optional]
 **shmsize** | **integer** | Size of '/dev/shm' in bytes. The size must be greater than 0. If omitted the system uses 64MB. | [optional]
 **squash** | **boolean** | Squash the resulting images layers into a single layer. *(Experimental release only.)* | [optional]
 **labels** | **string** | Arbitrary key/value labels to set on the image, as a JSON map of string pairs. | [optional]
 **networkmode** | **string** | Sets the networking mode for the run commands during build. Supported
standard values are: 'bridge', 'host', 'none', and 'container:<name|id>'.
Any other value is taken as a custom network's name or ID to which this
container should connect to. | [optional]
 **contentType** | **string** |  | [optional] [default to application/x-tar]
 **xRegistryConfig** | **string** | This is a base64-encoded JSON object with auth configurations for multiple registries that a build may refer to.

The key is a registry URL, and the value is an auth configuration object, [as described in the authentication section](#section/Authentication). For example:

'''
{
  \"docker.example.com\": {
    \"username\": \"janedoe\",
    \"password\": \"hunter2\"
  },
  \"https://index.docker.io/v1/\": {
    \"username\": \"mobydock\",
    \"password\": \"conta1n3rize14\"
  }
}
'''

Only the registry domain name (and port if not the default 443) are required. However, for legacy reasons, the Docker Hub registry must be specified with both a 'https://' prefix and a '/v1/' suffix even though Docker will prefer to use the v2 registry API. | [optional]
 **platform** | **string** | Platform in the format os[/arch[/variant]] | [optional] [default to ]
 **target** | **string** | Target build stage | [optional] [default to ]
 **outputs** | **string** | BuildKit output configuration | [optional] [default to ]
 **version** | **string** | Version of the builder backend to use.

- '1' is the first generation classic (deprecated) builder in the Docker daemon (default)
- '2' is [BuildKit](https://github.com/moby/buildkit) | [optional] [default to 1]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageCommit**

Create a new image from a container

### Example
```bash
 imageCommit  container=value  repo=value  tag=value  comment=value  author=value  pause=value  changes=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **containerConfig** | [**ContainerConfig**](ContainerConfig.md) | The container configuration | [optional]
 **container** | **string** | The ID or name of the container to commit | [optional]
 **repo** | **string** | Repository name for the created image | [optional]
 **tag** | **string** | Tag name for the create image | [optional]
 **comment** | **string** | Commit message | [optional]
 **author** | **string** | Author of the image (e.g., 'John Hannibal Smith <hannibal@a-team.com>') | [optional]
 **pause** | **boolean** | Whether to pause the container before committing | [optional] [default to true]
 **changes** | **string** | 'Dockerfile' instructions to apply while committing | [optional]

### Return type

[**IdResponse**](IdResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageCreate**

Create an image

Pull or import an image.

### Example
```bash
 imageCreate  fromImage=value  fromSrc=value  repo=value  tag=value  message=value X-Registry-Auth:value  Specify as:  changes=value1 changes=value2 changes=...  platform=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **fromImage** | **string** | Name of the image to pull. The name may include a tag or digest. This parameter may only be used when pulling an image. The pull is cancelled if the HTTP connection is closed. | [optional]
 **fromSrc** | **string** | Source to import. The value may be a URL from which the image can be retrieved or '-' to read the image from the request body. This parameter may only be used when importing an image. | [optional]
 **repo** | **string** | Repository name given to an image when it is imported. The repo may include a tag. This parameter may only be used when importing an image. | [optional]
 **tag** | **string** | Tag or digest. If empty when pulling an image, this causes all tags for the given image to be pulled. | [optional]
 **message** | **string** | Set commit message for imported image. | [optional]
 **inputImage** | **string** | Image content if the value '-' has been specified in fromSrc query parameter | [optional]
 **xRegistryAuth** | **string** | A base64url-encoded auth configuration.

Refer to the [authentication section](#section/Authentication) for
details. | [optional]
 **changes** | [**array[string]**](string.md) | Apply 'Dockerfile' instructions to the image that is created,
for example: 'changes=ENV DEBUG=true'.
Note that 'ENV DEBUG=true' should be URI component encoded.

Supported 'Dockerfile' instructions:
'CMD'|'ENTRYPOINT'|'ENV'|'EXPOSE'|'ONBUILD'|'USER'|'VOLUME'|'WORKDIR' | [optional]
 **platform** | **string** | Platform in the format os[/arch[/variant]].

When used in combination with the 'fromImage' option, the daemon checks
if the given image is present in the local image cache with the given
OS and Architecture, and otherwise attempts to pull the image. If the
option is not set, the host's native OS and Architecture are used.
If the given image does not exist in the local image cache, the daemon
attempts to pull the image with the host's native OS and Architecture.
If the given image does exists in the local image cache, but its OS or
architecture does not match, a warning is produced.

When used with the 'fromSrc' option to import an image from an archive,
this option sets the platform information for the imported image. If
the option is not set, the host's native OS and Architecture are used
for the imported image. | [optional] [default to ]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: text/plain, application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageDelete**

Remove an image

Remove an image, along with any untagged parent images that were
referenced by that image.

Images can't be removed if they have descendant images, are being
used by a running container or are being used by a build.

### Example
```bash
 imageDelete name=value  force=value  noprune=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | Image name or ID |
 **force** | **boolean** | Remove the image even if it is being used by stopped containers or has other tags | [optional] [default to false]
 **noprune** | **boolean** | Do not delete untagged parent images | [optional] [default to false]

### Return type

[**array[ImageDeleteResponseItem]**](ImageDeleteResponseItem.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageGet**

Export an image

Get a tarball containing all images and metadata for a repository.

If 'name' is a specific name and tag (e.g. 'ubuntu:latest'), then only that image (and its parents) are returned. If 'name' is an image ID, similarly only that image (and its parents) are returned, but with the exclusion of the 'repositories' file in the tarball, as there were no image names referenced.

### Image tarball format

An image tarball contains one directory per image layer (named using its long ID), each containing these files:

- 'VERSION': currently '1.0' - the file format version
- 'json': detailed layer information, similar to 'docker inspect layer_id'
- 'layer.tar': A tarfile containing the filesystem changes in this layer

The 'layer.tar' file contains 'aufs' style '.wh..wh.aufs' files and directories for storing attribute changes and deletions.

If the tarball defines a repository, the tarball should also include a 'repositories' file at the root that contains a list of repository and tag names mapped to layer IDs.

'''json
{
  \"hello-world\": {
    \"latest\": \"565a9d68a73f6706862bfe8409a7f659776d4d60a8d096eb4a3cbce6999cc2a1\"
  }
}
'''

### Example
```bash
 imageGet name=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | Image name or ID |

### Return type

**binary**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/x-tar

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageGetAll**

Export several images

Get a tarball containing all images and metadata for several image
repositories.

For each value of the 'names' parameter: if it is a specific name and
tag (e.g. 'ubuntu:latest'), then only that image (and its parents) are
returned; if it is an image ID, similarly only that image (and its parents)
are returned and there would be no names referenced in the 'repositories'
file for this image ID.

For details on the format, see the [export image endpoint](#operation/ImageGet).

### Example
```bash
 imageGetAll  Specify as:  names=value1 names=value2 names=...
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **names** | [**array[string]**](string.md) | Image names to filter by | [optional]

### Return type

**binary**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/x-tar

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageHistory**

Get the history of an image

Return parent layers of an image.

### Example
```bash
 imageHistory name=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | Image name or ID |

### Return type

[**array[HistoryResponseItem]**](HistoryResponseItem.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageInspect**

Inspect an image

Return low-level information about an image.

### Example
```bash
 imageInspect name=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | Image name or id |

### Return type

[**ImageInspect**](ImageInspect.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageList**

List Images

Returns a list of images on the server. Note that it uses a different, smaller representation of an image than inspecting a single image.

### Example
```bash
 imageList  all=value  filters=value  shared-size=value  digests=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **all** | **boolean** | Show all images. Only images from a final layer (no children) are shown by default. | [optional] [default to false]
 **filters** | **string** | A JSON encoded value of the filters (a 'map[string][]string') to
process on the images list.

Available filters:

- 'before'=('<image-name>[:<tag>]',  '<image id>' or '<image@digest>')
- 'dangling=true'
- 'label=key' or 'label=\"key=value\"' of an image label
- 'reference'=('<image-name>[:<tag>]')
- 'since'=('<image-name>[:<tag>]',  '<image id>' or '<image@digest>')
- 'until=<timestamp>' | [optional]
 **sharedSize** | **boolean** | Compute and show shared size as a 'SharedSize' field on each image. | [optional] [default to false]
 **digests** | **boolean** | Show digest information as a 'RepoDigests' field on each image. | [optional] [default to false]

### Return type

[**array[ImageSummary]**](ImageSummary.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageLoad**

Import images

Load a set of images and tags into a repository.

For details on the format, see the [export image endpoint](#operation/ImageGet).

### Example
```bash
 imageLoad  quiet=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **imagesTarball** | **binary** | Tar archive containing images | [optional]
 **quiet** | **boolean** | Suppress progress details during load. | [optional] [default to false]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/x-tar
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imagePrune**

Delete unused images

### Example
```bash
 imagePrune  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | Filters to process on the prune list, encoded as JSON (a 'map[string][]string'). Available filters:

- 'dangling=<boolean>' When set to 'true' (or '1'), prune only
   unused *and* untagged images. When set to 'false'
   (or '0'), all unused images are pruned.
- 'until=<string>' Prune images created before this timestamp. The '<timestamp>' can be Unix timestamps, date formatted timestamps, or Go duration strings (e.g. '10m', '1h30m') computed relative to the daemon machine’s time.
- 'label' ('label=<key>', 'label=<key>=<value>', 'label!=<key>', or 'label!=<key>=<value>') Prune images with (or without, in case 'label!=...' is used) the specified labels. | [optional]

### Return type

[**ImagePruneResponse**](ImagePruneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imagePush**

Push an image

Push an image to a registry.

If you wish to push an image on to a private registry, that image must
already have a tag which references the registry. For example,
'registry.example.com/myimage:latest'.

The push is cancelled if the HTTP connection is closed.

### Example
```bash
 imagePush name=value X-Registry-Auth:value  tag=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | Image name or ID. |
 **xRegistryAuth** | **string** | A base64url-encoded auth configuration.

Refer to the [authentication section](#section/Authentication) for
details. |
 **tag** | **string** | The tag to associate with the image on the registry. | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageSearch**

Search images

Search for an image on Docker Hub.

### Example
```bash
 imageSearch  term=value  limit=value  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **term** | **string** | Term to search |
 **limit** | **integer** | Maximum number of results to return | [optional]
 **filters** | **string** | A JSON encoded value of the filters (a 'map[string][]string') to process on the images list. Available filters:

- 'is-automated=(true|false)' (deprecated, see below)
- 'is-official=(true|false)'
- 'stars=<number>' Matches images that has at least 'number' stars.

The 'is-automated' filter is deprecated. The 'is_automated' field has
been deprecated by Docker Hub's search API. Consequently, searching
for 'is-automated=true' will yield no results. | [optional]

### Return type

[**array[ImageSearchResponseItem]**](ImageSearchResponseItem.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **imageTag**

Tag an image

Tag an image so that it becomes part of a repository.

### Example
```bash
 imageTag name=value  repo=value  tag=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | Image name or ID to tag. |
 **repo** | **string** | The repository to tag in. For example, 'someuser/someimage'. | [optional]
 **tag** | **string** | The name of the new tag. | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

