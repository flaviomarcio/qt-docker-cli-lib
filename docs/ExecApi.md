# ExecApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**containerExec**](ExecApi.md#containerExec) | **POST** /containers/{id}/exec | Create an exec instance
[**execInspect**](ExecApi.md#execInspect) | **GET** /exec/{id}/json | Inspect an exec instance
[**execResize**](ExecApi.md#execResize) | **POST** /exec/{id}/resize | Resize an exec instance
[**execStart**](ExecApi.md#execStart) | **POST** /exec/{id}/start | Start an exec instance


## **containerExec**

Create an exec instance

Run a command inside a running container.

### Example
```bash
 containerExec id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **execConfig** | [**ExecConfig**](ExecConfig.md) | Exec configuration |
 **id** | **string** | ID or name of container |

### Return type

[**IdResponse**](IdResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **execInspect**

Inspect an exec instance

Return low-level information about an exec instance.

### Example
```bash
 execInspect id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | Exec instance ID |

### Return type

[**ExecInspectResponse**](ExecInspectResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **execResize**

Resize an exec instance

Resize the TTY session used by an exec instance. This endpoint only works
if 'tty' was specified as part of creating and starting the exec instance.

### Example
```bash
 execResize id=value  h=value  w=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | Exec instance ID |
 **h** | **integer** | Height of the TTY session in characters | [optional]
 **w** | **integer** | Width of the TTY session in characters | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **execStart**

Start an exec instance

Starts a previously set up exec instance. If detach is true, this endpoint
returns immediately after starting the command. Otherwise, it sets up an
interactive session with the command.

### Example
```bash
 execStart id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | Exec instance ID |
 **execStartConfig** | [**ExecStartConfig**](ExecStartConfig.md) |  | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/vnd.docker.raw-stream, application/vnd.docker.multiplexed-stream

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

