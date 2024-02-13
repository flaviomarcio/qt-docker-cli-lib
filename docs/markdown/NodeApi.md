# NodeApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**nodeDelete**](NodeApi.md#nodeDelete) | **DELETE** /nodes/{id} | Delete a node
[**nodeInspect**](NodeApi.md#nodeInspect) | **GET** /nodes/{id} | Inspect a node
[**nodeList**](NodeApi.md#nodeList) | **GET** /nodes | List nodes
[**nodeUpdate**](NodeApi.md#nodeUpdate) | **POST** /nodes/{id}/update | Update a node


## **nodeDelete**

Delete a node

### Example
```bash
 nodeDelete id=value  force=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | The ID or name of the node |
 **force** | **boolean** | Force remove a node from the swarm | [optional] [default to false]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **nodeInspect**

Inspect a node

### Example
```bash
 nodeInspect id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | The ID or name of the node |

### Return type

[**Node**](Node.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **nodeList**

List nodes

### Example
```bash
 nodeList  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | Filters to process on the nodes list, encoded as JSON (a 'map[string][]string').

Available filters:
- 'id=<node id>'
- 'label=<engine label>'
- 'membership='('accepted'|'pending')'
- 'name=<node name>'
- 'node.label=<node label>'
- 'role='('manager'|'worker')' | [optional]

### Return type

[**array[Node]**](Node.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **nodeUpdate**

Update a node

### Example
```bash
 nodeUpdate id=value  version=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | The ID of the node |
 **version** | **integer** | The version number of the node object being updated. This is required
to avoid conflicting writes. |
 **body** | [**NodeSpec**](NodeSpec.md) |  | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

