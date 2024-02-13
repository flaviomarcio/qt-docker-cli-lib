# SystemApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**systemAuth**](SystemApi.md#systemAuth) | **POST** /auth | Check auth configuration
[**systemDataUsage**](SystemApi.md#systemDataUsage) | **GET** /system/df | Get data usage information
[**systemEvents**](SystemApi.md#systemEvents) | **GET** /events | Monitor events
[**systemInfo**](SystemApi.md#systemInfo) | **GET** /info | Get system information
[**systemPing**](SystemApi.md#systemPing) | **GET** /_ping | Ping
[**systemPingHead**](SystemApi.md#systemPingHead) | **HEAD** /_ping | Ping
[**systemVersion**](SystemApi.md#systemVersion) | **GET** /version | Get version


## **systemAuth**

Check auth configuration

Validate credentials for a registry and, if available, get an identity
token for accessing the registry without password.

### Example
```bash
 systemAuth
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **authConfig** | [**AuthConfig**](AuthConfig.md) | Authentication to check | [optional]

### Return type

[**SystemAuthResponse**](SystemAuthResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **systemDataUsage**

Get data usage information

### Example
```bash
 systemDataUsage  Specify as:  type=value1 type=value2 type=...
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **type** | [**array[string]**](string.md) | Object types, for which to compute and return data. | [optional]

### Return type

[**SystemDataUsageResponse**](SystemDataUsageResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **systemEvents**

Monitor events

Stream real-time events from the server.

Various objects within Docker report events when something happens to them.

Containers report these events: 'attach', 'commit', 'copy', 'create', 'destroy', 'detach', 'die', 'exec_create', 'exec_detach', 'exec_start', 'exec_die', 'export', 'health_status', 'kill', 'oom', 'pause', 'rename', 'resize', 'restart', 'start', 'stop', 'top', 'unpause', 'update', and 'prune'

Images report these events: 'delete', 'import', 'load', 'pull', 'push', 'save', 'tag', 'untag', and 'prune'

Volumes report these events: 'create', 'mount', 'unmount', 'destroy', and 'prune'

Networks report these events: 'create', 'connect', 'disconnect', 'destroy', 'update', 'remove', and 'prune'

The Docker daemon reports these events: 'reload'

Services report these events: 'create', 'update', and 'remove'

Nodes report these events: 'create', 'update', and 'remove'

Secrets report these events: 'create', 'update', and 'remove'

Configs report these events: 'create', 'update', and 'remove'

The Builder reports 'prune' events

### Example
```bash
 systemEvents  since=value  until=value  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **since** | **string** | Show events created since this timestamp then stream new events. | [optional]
 **_until** | **string** | Show events created until this timestamp then stop streaming. | [optional]
 **filters** | **string** | A JSON encoded value of filters (a 'map[string][]string') to process on the event list. Available filters:

- 'config=<string>' config name or ID
- 'container=<string>' container name or ID
- 'daemon=<string>' daemon name or ID
- 'event=<string>' event type
- 'image=<string>' image name or ID
- 'label=<string>' image or container label
- 'network=<string>' network name or ID
- 'node=<string>' node ID
- 'plugin'=<string> plugin name or ID
- 'scope'=<string> local or swarm
- 'secret=<string>' secret name or ID
- 'service=<string>' service name or ID
- 'type=<string>' object to filter by, one of 'container', 'image', 'volume', 'network', 'daemon', 'plugin', 'node', 'service', 'secret' or 'config'
- 'volume=<string>' volume name | [optional]

### Return type

[**EventMessage**](EventMessage.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **systemInfo**

Get system information

### Example
```bash
 systemInfo
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**SystemInfo**](SystemInfo.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **systemPing**

Ping

This is a dummy endpoint you can use to test if the server is accessible.

### Example
```bash
 systemPing
```

### Parameters
This endpoint does not need any parameter.

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **systemPingHead**

Ping

This is a dummy endpoint you can use to test if the server is accessible.

### Example
```bash
 systemPingHead
```

### Parameters
This endpoint does not need any parameter.

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **systemVersion**

Get version

Returns the version of Docker that is running and various information about the system that Docker is running on.

### Example
```bash
 systemVersion
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**SystemVersion**](SystemVersion.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

