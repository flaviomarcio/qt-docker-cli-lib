# NetworkApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**networkConnect**](NetworkApi.md#networkConnect) | **POST** /networks/{id}/connect | Connect a container to a network
[**networkCreate**](NetworkApi.md#networkCreate) | **POST** /networks/create | Create a network
[**networkDelete**](NetworkApi.md#networkDelete) | **DELETE** /networks/{id} | Remove a network
[**networkDisconnect**](NetworkApi.md#networkDisconnect) | **POST** /networks/{id}/disconnect | Disconnect a container from a network
[**networkInspect**](NetworkApi.md#networkInspect) | **GET** /networks/{id} | Inspect a network
[**networkList**](NetworkApi.md#networkList) | **GET** /networks | List networks
[**networkPrune**](NetworkApi.md#networkPrune) | **POST** /networks/prune | Delete unused networks


## **networkConnect**

Connect a container to a network

The network must be either a local-scoped network or a swarm-scoped network with the 'attachable' option set. A network cannot be re-attached to a running container

### Example
```bash
 networkConnect id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | Network ID or name |
 **container** | [**NetworkConnectRequest**](NetworkConnectRequest.md) |  |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **networkCreate**

Create a network

### Example
```bash
 networkCreate
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **networkConfig** | [**NetworkCreateRequest**](NetworkCreateRequest.md) | Network configuration |

### Return type

[**NetworkCreateResponse**](NetworkCreateResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **networkDelete**

Remove a network

### Example
```bash
 networkDelete id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | Network ID or name |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **networkDisconnect**

Disconnect a container from a network

### Example
```bash
 networkDisconnect id=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | Network ID or name |
 **container** | [**NetworkDisconnectRequest**](NetworkDisconnectRequest.md) |  |

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **networkInspect**

Inspect a network

### Example
```bash
 networkInspect id=value  verbose=value  scope=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **id** | **string** | Network ID or name |
 **verbose** | **boolean** | Detailed inspect output for troubleshooting | [optional] [default to false]
 **scope** | **string** | Filter the network by scope (swarm, global, or local) | [optional]

### Return type

[**Network**](Network.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **networkList**

List networks

Returns a list of networks. For details on the format, see the
[network inspect endpoint](#operation/NetworkInspect).

Note that it uses a different, smaller representation of a network than
inspecting a single network. For example, the list of containers attached
to the network is not propagated in API versions 1.28 and up.

### Example
```bash
 networkList  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | JSON encoded value of the filters (a 'map[string][]string') to process
on the networks list.

Available filters:

- 'dangling=<boolean>' When set to 'true' (or '1'), returns all
   networks that are not in use by a container. When set to 'false'
   (or '0'), only networks that are in use by one or more
   containers are returned.
- 'driver=<driver-name>' Matches a network's driver.
- 'id=<network-id>' Matches all or part of a network ID.
- 'label=<key>' or 'label=<key>=<value>' of a network label.
- 'name=<network-name>' Matches all or part of a network name.
- 'scope=[\"swarm\"|\"global\"|\"local\"]' Filters networks by scope ('swarm', 'global', or 'local').
- 'type=[\"custom\"|\"builtin\"]' Filters networks by type. The 'custom' keyword returns all user-defined networks. | [optional]

### Return type

[**array[Network]**](Network.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **networkPrune**

Delete unused networks

### Example
```bash
 networkPrune  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | Filters to process on the prune list, encoded as JSON (a 'map[string][]string').

Available filters:
- 'until=<timestamp>' Prune networks created before this timestamp. The '<timestamp>' can be Unix timestamps, date formatted timestamps, or Go duration strings (e.g. '10m', '1h30m') computed relative to the daemon machine’s time.
- 'label' ('label=<key>', 'label=<key>=<value>', 'label!=<key>', or 'label!=<key>=<value>') Prune networks with (or without, in case 'label!=...' is used) the specified labels. | [optional]

### Return type

[**NetworkPruneResponse**](NetworkPruneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

