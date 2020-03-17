* В алгоритме, предусмотренном американским национальным стандартом NAVSO P-5239-26 для MFM-кодируемых устройств: в первом цикле записывается #01, во втором — #7FFFFFF, в третьем — последовательность псевдослучайных чисел, в четвёртом проходит верификация. В варианте для RLL — кодируемых устройств данного алгоритма во втором цикле записывается #27FFFFFF
* В алгоритме, описываемом германским национальным стандартом VSITR, с первого по шестой цикл записываются последовательно байты #00 и #FF, в седьмом #AA.
* Многими заявляется[уточнить] о существовании алгоритма, описанного российским государственным стандартом ГОСТ P 50739-95, предусматривающего запись #00 в каждый байт каждого сектора для систем с 4-6 класса защиты и запись псевдослучайных чисел в каждый байт каждого сектора для систем 1-3 класса защиты[3]. Однако данный ГОСТ содержит лишь формулировку «Очистка должна производиться путём записи маскирующей информации в память при её освобождении перераспределении», которая не содержит какой-либо детализации относительно порядка перезаписи, количества циклов и битовых масок[4]. В то же время, существует действующий руководящий документ Государственно технической комиссии России «Автоматизированные системы. Защита от несанкционированного доступа к информации. Классификация автоматизированных систем и требования по защите информации», изданный в 1992 году и предусматривающий ряд требований к механизму уничтожения информации для систем определённых классов защищенности. В частности, для классов 3А и 2A «Очистка осуществляется двукратной произвольной записью в освобождаемую область памяти, ранее использованную для хранения защищаемых данных (файлов)», для класса 1Г предусмотрена однократная перезапись.[5]
* В алгоритме Парагона первый цикл заключается в перезаписи уникальными 512-битными блоками, используя криптографически безопасный генератор случайных чисел. Затем — во втором цикле — каждый перезаписываемый блок переписывается своим двоичным дополнением. Третий цикл повторяет первый цикл с новыми уникальными случайными блокам. В четвёртом цикле происходит перезапись байтом #AA. Завершается уничтожение информации циклом верификации.