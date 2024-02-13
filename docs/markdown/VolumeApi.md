# VolumeApi

All URIs are relative to */v1.44*

Method | HTTP request | Description
------------- | ------------- | -------------
[**volumeCreate**](VolumeApi.md#volumeCreate) | **POST** /volumes/create | Create a volume
[**volumeDelete**](VolumeApi.md#volumeDelete) | **DELETE** /volumes/{name} | Remove a volume
[**volumeInspect**](VolumeApi.md#volumeInspect) | **GET** /volumes/{name} | Inspect a volume
[**volumeList**](VolumeApi.md#volumeList) | **GET** /volumes | List volumes
[**volumePrune**](VolumeApi.md#volumePrune) | **POST** /volumes/prune | Delete unused volumes
[**volumeUpdate**](VolumeApi.md#volumeUpdate) | **PUT** /volumes/{name} | \&quot;Update a volume. Valid only for Swarm cluster volumes\&quot;


## **volumeCreate**

Create a volume

### Example
```bash
 volumeCreate
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **volumeConfig** | [**VolumeCreateOptions**](VolumeCreateOptions.md) | Volume configuration |

### Return type

[**Volume**](Volume.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **volumeDelete**

Remove a volume

Instruct the driver to remove the volume.

### Example
```bash
 volumeDelete name=value  force=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | Volume name or ID |
 **force** | **boolean** | Force the removal of the volume | [optional] [default to false]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json, text/plain

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **volumeInspect**

Inspect a volume

### Example
```bash
 volumeInspect name=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | Volume name or ID |

### Return type

[**Volume**](Volume.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **volumeList**

List volumes

### Example
```bash
 volumeList  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | JSON encoded value of the filters (a 'map[string][]string') to
process on the volumes list. Available filters:

- 'dangling=<boolean>' When set to 'true' (or '1'), returns all
   volumes that are not in use by a container. When set to 'false'
   (or '0'), only volumes that are in use by one or more
   containers are returned.
- 'driver=<volume-driver-name>' Matches volumes based on their driver.
- 'label=<key>' or 'label=<key>:<value>' Matches volumes based on
   the presence of a 'label' alone or a 'label' and a value.
- 'name=<volume-name>' Matches all or part of a volume name. | [optional]

### Return type

[**VolumeListResponse**](VolumeListResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **volumePrune**

Delete unused volumes

### Example
```bash
 volumePrune  filters=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **filters** | **string** | Filters to process on the prune list, encoded as JSON (a 'map[string][]string').

Available filters:
- 'label' ('label=<key>', 'label=<key>=<value>', 'label!=<key>', or 'label!=<key>=<value>') Prune volumes with (or without, in case 'label!=...' is used) the specified labels.
- 'all' ('all=true') - Consider all (local) volumes for pruning and not just anonymous volumes. | [optional]

### Return type

[**VolumePruneResponse**](VolumePruneResponse.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json, text/plain
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

## **volumeUpdate**

\"Update a volume. Valid only for Swarm cluster volumes\"

### Example
```bash
 volumeUpdate name=value  version=value
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **name** | **string** | The name or ID of the volume |
 **version** | **integer** | The version number of the volume being updated. This is required to
avoid conflicting writes. Found in the volume's 'ClusterVolume'
field. |
 **body** | [**Body**](Body.md) | The spec of the volume to update. Currently, only Availability may
change. All other fields must remain unchanged. | [optional]

### Return type

(empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

