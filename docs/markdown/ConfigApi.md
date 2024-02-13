# ConfigApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**configCreate**](ConfigApi.md#configCreate) | **POST** /configs/create | Create a config
[**configDelete**](ConfigApi.md#configDelete) | **DELETE** /configs/{id} | Delete a config
[**configInspect**](ConfigApi.md#configInspect) | **GET** /configs/{id} | Inspect a config
[**configList**](ConfigApi.md#configList) | **GET** /configs | List configs
[**configUpdate**](ConfigApi.md#configUpdate) | **POST** /configs/{id}/update | Update a Config


## **configCreate**

Create a config

### Example
```bash
 configCreate
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **body** | [**object**](.md) |  | [optional]

### Return type

[**IdResponse**](IdResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **configDelete**

Delete a config

### Example
```bash
 configDelete id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID of the config |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **configInspect**

Inspect a config

### Example
```bash
 configInspect id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID of the config |

### Return type

[**Config**](Config.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **configList**

List configs

### Example
```bash
 configList  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | A JSON encoded value of the filters (a 'map[string][]string') to
process on the configs list.

Available filters:

- 'id=<config id>'
- 'label=<key> or label=<key>=value'
- 'name=<config name>'
- 'names=<config name>' | [optional]

### Return type

[**array[Config]**](Config.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **configUpdate**

Update a Config

### Example
```bash
 configUpdate id=value  version=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | The ID or name of the config |
 **version** | **integer** | The version number of the config object being updated. This is
required to avoid conflicting writes. |
 **body** | [**ConfigSpec**](ConfigSpec.md) | The spec of the config to update. Currently, only the Labels field
can be updated. All other fields must remain unchanged from the
[ConfigInspect endpoint](#operation/ConfigInspect) response values. | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

