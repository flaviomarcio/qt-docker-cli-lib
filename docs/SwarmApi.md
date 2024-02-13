# SwarmApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**swarmInit**](SwarmApi.md#swarmInit) | **POST** /swarm/init | Initialize a new swarm
[**swarmInspect**](SwarmApi.md#swarmInspect) | **GET** /swarm | Inspect swarm
[**swarmJoin**](SwarmApi.md#swarmJoin) | **POST** /swarm/join | Join an existing swarm
[**swarmLeave**](SwarmApi.md#swarmLeave) | **POST** /swarm/leave | Leave a swarm
[**swarmUnlock**](SwarmApi.md#swarmUnlock) | **POST** /swarm/unlock | Unlock a locked manager
[**swarmUnlockkey**](SwarmApi.md#swarmUnlockkey) | **GET** /swarm/unlockkey | Get the unlock key
[**swarmUpdate**](SwarmApi.md#swarmUpdate) | **POST** /swarm/update | Update a swarm


## **swarmInit**

Initialize a new swarm

### Example
```bash
 swarmInit
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**SwarmInitRequest**](SwarmInitRequest.md) |  |

### Return type

**string**

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **swarmInspect**

Inspect swarm

### Example
```bash
 swarmInspect
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**Swarm**](Swarm.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **swarmJoin**

Join an existing swarm

### Example
```bash
 swarmJoin
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**SwarmJoinRequest**](SwarmJoinRequest.md) |  |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **swarmLeave**

Leave a swarm

### Example
```bash
 swarmLeave  force=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **force** | **boolean** | Force leave swarm, even if this is the last manager or that it will
break the cluster. | [optional] [default to false]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **swarmUnlock**

Unlock a locked manager

### Example
```bash
 swarmUnlock
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**SwarmUnlockRequest**](SwarmUnlockRequest.md) |  |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **swarmUnlockkey**

Get the unlock key

### Example
```bash
 swarmUnlockkey
```

### Parameters
This endpoint does not need any parameter.

### Return type

[**UnlockKeyResponse**](UnlockKeyResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **swarmUpdate**

Update a swarm

### Example
```bash
 swarmUpdate  version=value  rotateWorkerToken=value  rotateManagerToken=value  rotateManagerUnlockKey=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**SwarmSpec**](SwarmSpec.md) |  |
 **version** | **integer** | The version number of the swarm object being updated. This is
required to avoid conflicting writes. |
 **rotateWorkerToken** | **boolean** | Rotate the worker join token. | [optional] [default to false]
 **rotateManagerToken** | **boolean** | Rotate the manager join token. | [optional] [default to false]
 **rotateManagerUnlockKey** | **boolean** | Rotate the manager unlock key. | [optional] [default to false]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

