# ASF Header Parser

_**Functionality improvement is in progress**_

**This program is designed to parse the ASF file's header (actually .wmv)**

## Compilation

```bash
makefile soon...
```

## Usage

```bash
./ASFHeaderParser /absolute/path/to/filename.wmv
```

## ASF Documentation

[Online documentation](https://docs.microsoft.com/en-us/windows/win32/medfound/asf-file-structure)

[Download doc with ASF specification](https://www.microsoft.com/downloads/details.aspx?displaylang=en&FamilyID=56de5ee4-51ca-46c6-903b-97390ad14fea)

## Supported Header Structure

* **Header Object**
    * **File Properties Object**
    * **Stream Properties Object**
        * **Type Specific Data**
            * **Format Data**
        * _Soon..._
    * **Header Extension Object**
        * _Soon..._
    * **Codec List Object**
    * **Script Command Object**
    * **Marker Object**
    * **Bitrate Mutual Exclusion Object**
    * **Error Correction Object**
        * _Soon..._
    * **Content Description Object**
    * **Extended Content Description Object**
    * **Stream Bitrate Properties Object**
    * **Content Branding Object**
    * **Content Encryption Object**
    * **Extended Content Encryption Object**
    * **Digital Signature Object**
    * **Padding Object**

## Class Structure

* `Object`
    * `HeaderObject`
    * `FilePropertiesObject`
    * `StreamPropertiesObject`
        * `VideoData`
            * `FormatData`
        * _Soon..._
    * `HeaderExtensionObject`
        * _Soon..._
    * `CodecListObject`
        * `CodecEntry`
    * `ScriptCommandObject`
        * `CommandType`
        * `Command`
    * `MarkerObject`
        * `Marker`
    * `BitrateMutualExclusionObject`
    * `ErrorCorrectionObject`
        * _Soon..._
    * `ContentDescriptionObject`
    * `ExtendedContentDescriptionObject`
        * `ContentDescriptor`
    * `StreamBitratePropertiesObject`
        * `BitrateRecord`
    * `ContentBrandingObject`
    * `ContentEncryptionObject`
    * `ExtendedContentEncryptionObject`
    * `DigitalSignatureObject`
    * `PaddingObject`

## Extracted data

* _Soon..._
