$MINGW_PATH = Join-Path (Get-Location) "lib\mingw32\bin"
$env:PATH = "$MINGW_PATH;$env:PATH"
echo "Environment set up success!"
