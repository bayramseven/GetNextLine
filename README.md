*This project has been created as part of the 42 curriculum by bayseven.*

# get_next_line

## Description

Bu proje, 42 müfredatındaki `get_next_line` fonksiyonunun basit bir versiyonunu uygular. Amaç, bir dosya tanımlayıcısından satır satır okumak, her çağrıda bir satır döndürmek ve okunmamış kalan veriyi sonraki çağrılar için saklamaktır. Bu uygulama, geçerli tüm dosya tanımlayıcılarından okuma yapacak şekilde tasarlanmıştır ve kısmi okuma durumlarını statik bir tampon kullanarak yönetir.

## Instructions

1. `get_next_line.c`, `get_next_line_utils.c` ve `get_next_line.h` dosyalarını aynı klasöre yerleştirin.
2. Gerekirse `BUFFER_SIZE` tanımlaması ile birlikte standart 42 bayrakları kullanarak derleyin.

Örnek derleme komutu:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```

3. Kendi `main` programınızda `get_next_line` fonksiyonunu kullanarak bir dosya tanımlayıcısından satır satır okuyun.

Örnek kullanım:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algoritma

Bu uygulama, `get_next_line` fonksiyonunun ardışık çağrıları arasında okunmamış veriyi saklamak için statik bir `store` tamponu kullanır.

Adımlar:

1. `read_store(fd, store)` fonksiyonu, `BUFFER_SIZE` boyutunda geçici bir tampon kullanarak dosya tanımlayıcısından okuma yapar.
2. Fonksiyon, bir yeni satır karakteri bulunana veya dosyanın sonuna ulaşılana kadar yeni okunan veriyi mevcut `store` değişkenine ekler.
3. `get_clean_line(store)` fonksiyonu, `store` içerisinden döndürülecek sonraki satırı çıkarır; varsa yeni satır karakterini de satıra dahil eder.
4. `update_store(store)` fonksiyonu, döndürülen satırı `store` içerisinden kaldırır ve kalan veriyi sonraki çağrı için saklar.

Neden bu algoritma?

- Statik tampon kullanımı, ardışık `get_next_line` çağrıları arasında kalan veriyi tutarak satır satır okumayı mümkün kılar.
- `BUFFER_SIZE` makrosu, `read` çağrısının okuma blok boyutunu kontrol eder ve performans ile bellek kullanımı arasında denge sağlar.
- Fonksiyonları `read_store`, `get_clean_line` ve `update_store` olarak ayırmak, kodun okunabilirliğini ve bellek yönetimini iyileştirir.
- Dosya tanımlayıcısı geçerliliği kontrol edilir, bellek tahsisi `ft_calloc` ile yapılır ve hatalarda tamponlar serbest bırakılır, böylece tanımsız davranışlardan kaçınılır.

## Resources

- 42 `get_next_line` konu açıklaması
- https://www.geeksforgeeks.org/c/static-variables-in-c/
- https://www.tutorialspoint.com/cprogramming/c_storage_classes.htm
- https://www.codecademy.com/resources/docs/c/static-variables
- https://www.w3schools.com/c/ref_keyword_static.php
- https://man7.org/linux/man-pages/man2/read.2.html
- https://www.geeksforgeeks.org/c/memory-layout-of-c-program/

### AI Kullanımı

Bu `README.md` belgesinin oluşturulmasında AI'dan yardım alındı. Proje koduna AI tarafından üretilmiş herhangi bir kod eklenmedi.
