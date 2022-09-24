## Чекпоинт 7 (одиночный). Создание исполняемого файла.

### Дедлайн - ??

Последний шаг до готового компилятора!  
В прошлом чекпоинте вы подготовили LLVM IR, который далее компилируется clang-ом в исполняемый файл. Почему бы теперь не заменить clang в этом пайплайне?  

Цель этого чекпоинта - самостоятельно собрать исполняемый файл на основе IR модуля, что вы создали ранее.  
Здесь вам нужно будет разобраться с target triple и как передать target triple системы внутрь LLVM.  

Поэкспериментируйте также со встроенными optimization pass-ами LLVM. Одним из следующих опциональных чекпоинтов будет написание такого пасса самостоятельно.  

Этот чекпоинт является завершающим в разработке компилятора, но впереди остаётся ещё много работы: нужно грамотно обрабатывать ошибки, писать тесты и вообще всесторонне улучшать архитектуру.  
Следующие чекпоинты будут опциональными и они как раз об этом -- всестороннем улучшении вашего компилятора.