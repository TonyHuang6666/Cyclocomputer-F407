del *.bak /s
del *.ddk /s
del *.edk /s
del *.lst /s
del *.lnp /s
del *.mpf /s
del *.mpj /s
del *.obj /s
del *.omf /s
::del *.opt /s  ::������ɾ��JLINK������
del *.plg /s
del *.rpt /s
del *.tmp /s
del *.__i /s
del *.crf /s
del *.o /s
del *.d /s
del *.axf /s
del *.tra /s
del *.dep /s           
del JLinkLog.txt /s

del *.iex /s
del *.htm /s
del *.map /s
del *.clangd /s

@echo off
set "folder=DebugConfig"

if exist "%folder%" (
    echo Deleting folder "%folder%" and its contents...
    rd /s /q "%folder%"
    echo Folder "%folder%" deleted successfully.
) else (
    echo Folder "%folder%" not found.
)

@echo off
set "folder=Listings"

if exist "%folder%" (
    echo Deleting folder "%folder%" and its contents...
    rd /s /q "%folder%"
    echo Folder "%folder%" deleted successfully.
) else (
    echo Folder "%folder%" not found.
)

@echo off
set "folder=Objects"

if exist "%folder%" (
    echo Deleting folder "%folder%" and its contents...
    rd /s /q "%folder%"
    echo Folder "%folder%" deleted successfully.
) else (
    echo Folder "%folder%" not found.
)

@echo off
set "folder=out"

if exist "%folder%" (
    echo Deleting folder "%folder%" and its contents...
    rd /s /q "%folder%"
    echo Folder "%folder%" deleted successfully.
) else (
    echo Folder "%folder%" not found.
)

@echo off
set "folder=RTE"

if exist "%folder%" (
    echo Deleting folder "%folder%" and its contents...
    rd /s /q "%folder%"
    echo Folder "%folder%" deleted successfully.
) else (
    echo Folder "%folder%" not found.
)

@echo off
set "folder=tmp"

if exist "%folder%" (
    echo Deleting folder "%folder%" and its contents...
    rd /s /q "%folder%"
    echo Folder "%folder%" deleted successfully.
) else (
    echo Folder "%folder%" not found.
)

exit
