# Fonction général:

grep -R '_printf' . --include="*.c" --exclude-dir="bootstrap" > res1 ; grep -R 'printf' . --include="*.c" --exclude-dir="bootstrap" > res2
grep -R 'my_strlen' . --include="*.c" --exclude-dir="bootstrap" >> res1 ; grep -R 'strlen' . --include="*.c" --exclude-dir="bootstrap" >> res2
grep -R 'my_strcat' . --include="*.c" --exclude-dir="bootstrap" >> res1 ; grep -R 'strcat' . --include="*.c" --exclude-dir="bootstrap" >> res2
grep -R 'my_strcmp' . --include="*.c" --exclude-dir="bootstrap" >> res1 ; grep -R 'strcmp' . --include="*.c" --exclude-dir="bootstrap" >> res2
grep -R 'my_strncmp' . --include="*.c" --exclude-dir="bootstrap" >> res1 ; grep -R 'strncmp' . --include="*.c" --exclude-dir="bootstrap" >> res2
grep -R 'my_strcpy' . --include="*.c" --exclude-dir="bootstrap" >> res1 ; grep -R 'strcpy' . --include="*.c" --exclude-dir="bootstrap" >> res2
grep -R 'my_strncpy' . --include="*.c" --exclude-dir="bootstrap" >> res1 ; grep -R 'strncpy' . --include="*.c" --exclude-dir="bootstrap" >> res2
grep -R 'my_strdup' . --include="*.c" --exclude-dir="bootstrap" >> res1 ; grep -R 'strdup' . --include="*.c" --exclude-dir="bootstrap" >> res2
grep -R 'system' . --include="*.c" --exclude-dir="bootstrap" >> res2

if diff res1 res2
then
    echo 'no problem'
    rm -f res1 ; rm -f res2
    exit 0
else
    echo 'banned function'
    exit 1
fi