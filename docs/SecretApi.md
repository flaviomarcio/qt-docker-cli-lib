# SecretApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**secretCreate**](SecretApi.md#secretCreate) | **POST** /secrets/create | Create a secret
[**secretDelete**](SecretApi.md#secretDelete) | **DELETE** /secrets/{id} | Delete a secret
[**secretInspect**](SecretApi.md#secretInspect) | **GET** /secrets/{id} | Inspect a secret
[**secretList**](SecretApi.md#secretList) | **GET** /secrets | List secrets
[**secretUpdate**](SecretApi.md#secretUpdate) | **POST** /secrets/{id}/update | Update a Secret


## **secretCreate**

Create a secret

### Example
```bash
 secretCreate
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

## **secretDelete**

Delete a secret

### Example
```bash
 secretDelete id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID of the secret |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **secretInspect**

Inspect a secret

### Example
```bash
 secretInspect id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | ID of the secret |

### Return type

[**Secret**](Secret.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **secretList**

List secrets

### Example
```bash
 secretList  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | A JSON encoded value of the filters (a 'map[string][]string') to
process on the secrets list.

Available filters:

- 'id=<secret id>'
- 'label=<key> or label=<key>=value'
- 'name=<secret name>'
- 'names=<secret name>' | [optional]

### Return type

[**array[Secret]**](Secret.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **secretUpdate**

Update a Secret

### Example
```bash
 secretUpdate id=value  version=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | The ID or name of the secret |
 **version** | **integer** | The version number of the secret object being updated. This is
required to avoid conflicting writes. |
 **body** | [**SecretSpec**](SecretSpec.md) | The spec of the secret to update. Currently, only the Labels field
can be updated. All other fields must remain unchanged from the
[SecretInspect endpoint](#operation/SecretInspect) response values. | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

