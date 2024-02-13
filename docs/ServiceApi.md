# ServiceApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**serviceCreate**](ServiceApi.md#serviceCreate) | **POST** /services/create | Create a service
[**serviceDelete**](ServiceApi.md#serviceDelete) | **DELETE** /services/{id} | Delete a service
[**serviceInspect**](ServiceApi.md#serviceInspect) | **GET** /services/{id} | Inspect a service
[**serviceList**](ServiceApi.md#serviceList) | **GET** /services | List services
[**serviceLogs**](ServiceApi.md#serviceLogs) | **GET** /services/{id}/logs | Get service logs
[**serviceUpdate**](ServiceApi.md#serviceUpdate) | **POST** /services/{id}/update | Update a service


## **serviceCreate**

Create a service

### Example
```bash
 serviceCreate X-Registry-Auth:value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**object**](.md) |  |
 **xRegistryAuth** | **string** | A base64url-encoded auth configuration for pulling from private
registries.

Refer to the [authentication section](#section/Authentication) for
details. | [optional]

### Return type

[**ServiceCreateResponse**](ServiceCreateResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **serviceDelete**

Delete a service

### Example
```bash
 serviceDelete id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of service. |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **serviceInspect**

Inspect a service

### Example
```bash
 serviceInspect id=value  insertDefaults=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of service. |
 **insertDefaults** | **boolean** | Fill empty fields with default values. | [optional] [default to false]

### Return type

[**Service**](Service.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **serviceList**

List services

### Example
```bash
 serviceList  filters=value  status=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | A JSON encoded value of the filters (a 'map[string][]string') to
process on the services list.

Available filters:

- 'id=<service id>'
- 'label=<service label>'
- 'mode=[\"replicated\"|\"global\"]'
- 'name=<service name>' | [optional]
 **status** | **boolean** | Include service status, with count of running and desired tasks. | [optional]

### Return type

[**array[Service]**](Service.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **serviceLogs**

Get service logs

Get 'stdout' and 'stderr' logs from a service. See also
['/containers/{id}/logs'](#operation/ContainerLogs).

**Note**: This endpoint works only for services with the 'local',
'json-file' or 'journald' logging drivers.

### Example
```bash
 serviceLogs id=value  details=value  follow=value  stdout=value  stderr=value  since=value  timestamps=value  tail=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of the service |
 **details** | **boolean** | Show service context and extra details provided to logs. | [optional] [default to false]
 **follow** | **boolean** | Keep connection after returning logs. | [optional] [default to false]
 **stdout** | **boolean** | Return logs from 'stdout' | [optional] [default to false]
 **stderr** | **boolean** | Return logs from 'stderr' | [optional] [default to false]
 **since** | **integer** | Only return logs since this time, as a UNIX timestamp | [optional] [default to 0]
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

## **serviceUpdate**

Update a service

### Example
```bash
 serviceUpdate id=value  version=value  registryAuthFrom=value  rollback=value X-Registry-Auth:value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID or name of service. |
 **body** | [**object**](.md) |  |
 **version** | **integer** | The version number of the service object being updated. This is
required to avoid conflicting writes.
This version number should be the value as currently set on the
service *before* the update. You can find the current version by
calling 'GET /services/{id}' |
 **registryAuthFrom** | **string** | If the 'X-Registry-Auth' header is not specified, this parameter
indicates where to find registry authorization credentials. | [optional] [default to spec]
 **rollback** | **string** | Set to this parameter to 'previous' to cause a server-side rollback
to the previous service spec. The supplied spec will be ignored in
this case. | [optional]
 **xRegistryAuth** | **string** | A base64url-encoded auth configuration for pulling from private
registries.

Refer to the [authentication section](#section/Authentication) for
details. | [optional]

### Return type

[**ServiceUpdateResponse**](ServiceUpdateResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

