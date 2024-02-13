# Resources

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**CpuShares** | **integer** |  | [optional] [default to null]
**Memory** | **integer** |  | [optional] [default to 0]
**CgroupParent** | **string** |  | [optional] [default to null]
**BlkioWeight** | **integer** |  | [optional] [default to null]
**BlkioWeightDevice** | [**array[Resources_BlkioWeightDevice]**](Resources_BlkioWeightDevice.md) |  | [optional] [default to null]
**BlkioDeviceReadBps** | [**array[ThrottleDevice]**](ThrottleDevice.md) |  | [optional] [default to null]
**BlkioDeviceWriteBps** | [**array[ThrottleDevice]**](ThrottleDevice.md) |  | [optional] [default to null]
**BlkioDeviceReadIOps** | [**array[ThrottleDevice]**](ThrottleDevice.md) |  | [optional] [default to null]
**BlkioDeviceWriteIOps** | [**array[ThrottleDevice]**](ThrottleDevice.md) |  | [optional] [default to null]
**CpuPeriod** | **integer** |  | [optional] [default to null]
**CpuQuota** | **integer** |  | [optional] [default to null]
**CpuRealtimePeriod** | **integer** |  | [optional] [default to null]
**CpuRealtimeRuntime** | **integer** |  | [optional] [default to null]
**CpusetCpus** | **string** |  | [optional] [default to null]
**CpusetMems** | **string** |  | [optional] [default to null]
**Devices** | [**array[DeviceMapping]**](DeviceMapping.md) |  | [optional] [default to null]
**DeviceCgroupRules** | **array[string]** |  | [optional] [default to null]
**DeviceRequests** | [**array[DeviceRequest]**](DeviceRequest.md) |  | [optional] [default to null]
**KernelMemoryTCP** | **integer** |  | [optional] [default to null]
**MemoryReservation** | **integer** |  | [optional] [default to null]
**MemorySwap** | **integer** |  | [optional] [default to null]
**MemorySwappiness** | **integer** |  | [optional] [default to null]
**NanoCpus** | **integer** |  | [optional] [default to null]
**OomKillDisable** | **boolean** |  | [optional] [default to null]
**Init** | **boolean** |  | [optional] [default to null]
**PidsLimit** | **integer** |  | [optional] [default to null]
**Ulimits** | [**array[Resources_Ulimits]**](Resources_Ulimits.md) |  | [optional] [default to null]
**CpuCount** | **integer** |  | [optional] [default to null]
**CpuPercent** | **integer** |  | [optional] [default to null]
**IOMaximumIOps** | **integer** |  | [optional] [default to null]
**IOMaximumBandwidth** | **integer** |  | [optional] [default to null]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


