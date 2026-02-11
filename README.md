Progress bar con observer, visualizzazione con QT

Classi principali

ResourceLoader:
Simula il caricamento dei file ed emette un segnale al cambiamento della percentuale di caricamento.

ProgressObserver:
Agisce da Observer, riceve il segnale da ResourcLoader e aggiorna visivamente il valore della QProgressBar.

MainWindow:
gestisce il setup dell'applicazione: istanzia gli oggetti e stabilisce la connessione tra il segnale di ResourceLoader e lo slot di ProgressObserver.

Unit Test
Implementato con Google Test, per eseguire i test digitare sul terminale: .\testing.bat

Test 1, ResourceLoaderTest:
Verifico che l'oggetto esista.

Test 2, ResourceLoaderTest:
Verifica logica caricamento.

Test 3, ProgressObserverTest:
verifico che il valore della percentuale di caricamento passi alla barra.

Test 4, ProgressObserverTest:
Verifico che m_progressBar non crashi con nullptr.
