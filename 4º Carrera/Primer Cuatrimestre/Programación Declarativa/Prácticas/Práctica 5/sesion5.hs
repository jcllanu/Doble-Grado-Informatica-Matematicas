--Juan Carlos Llamas Núñez 4ºDG Mat-Inf
--1
getInt = do line <- getLine
            return (read line::Int)
adivina :: Int -> IO()
adivina n = do putStrLn "Adivina el número que estoy pensando (Introduce un valor entero): "
               x <- getInt
               if x==n then do putStrLn "Muy bien!!! Has acertado!!!"
                               return ()
                       else if x > n then do putStrLn "Casi lo tienes. Prueba con un número más pequeño."
                                             adivina n
                                     else do putStrLn "Casi lo tienes. Prueba con un número más grande."
                                             adivina n
--2
data Matriz = M (Int,Int,[[Int]])
leerMatriz :: IO Matriz
leerMatriz = do putStrLn "Introduce el número de filas de la matriz (Entero positivo):"
                filas <- getInt
                putStrLn "Introduce el número de columnas de la matriz (Entero positivo):"
                columnas <- getInt
                putStrLn "Introduce las entradas de la matriz por filas número a número."
                putStrLn ("Si A=(a_i_j)1<=i<="++(show filas)++", 1<=j<="++(show columnas)++", entonces primero se te pedirá introducir a_1_1, después a_1_2,... hasta a_1_"++(show columnas))
                putStrLn "...y así con todas las filas.\n"
                matriz <- leerMatrizAuxiliar filas columnas []
                return (M (filas,columnas,matriz))

leerMatrizAuxiliar :: Int -> Int-> [[Int]] -> IO [[Int]]
leerMatrizAuxiliar filas columnas matriz = do if filas>0 then do putStrLn "Comienza una nueva fila."
                                                                 fila <- leerFila columnas []
                                                                 leerMatrizAuxiliar (filas-1) columnas (matriz++[fila])
                                                         else do return matriz

leerFila :: Int -> [Int] -> IO [Int]
leerFila columnas fila = if columnas==0 then do return fila
                                        else do putStrLn "Introduce la siguiente entrada de la matriz:"
                                                x <- getInt
                                                leerFila (columnas-1) (fila++[x])

dibujaMatriz :: Matriz -> IO()
dibujaMatriz (M (filas,columnas,matriz)) = do dibujarMatrizAuxiliar filas columnas matriz

dibujarMatrizAuxiliar :: Int -> Int -> [[Int]] -> IO()
dibujarMatrizAuxiliar filas columnas matriz = do if filas>0 then do escribirFila columnas (head matriz)
                                                                    putStrLn ""
                                                                    dibujarMatrizAuxiliar (filas-1) columnas (tail matriz)
                                                            else do return ()
escribirFila :: Int -> [Int] -> IO()
escribirFila columnas fila =  if columnas==0 then do return ()
                                             else do putStr (show(head fila) ++ " ")
                                                     escribirFila (columnas-1) (tail fila)

dibujaMatrizbis :: Matriz -> IO()
dibujaMatrizbis (M (filas,columnas,matriz)) = do putStrLn(matrizAString filas columnas matriz [])

matrizAString :: Int -> Int -> [[Int]] -> String -> String
matrizAString filas columnas matriz acc= if filas>0 then matrizAString (filas-1) columnas (tail matriz) (acc++"\n"++(filaAString columnas (head matriz) []))
                                                    else acc

filaAString :: Int -> [Int] -> String -> String
filaAString columnas fila acc=  if columnas==0 then acc
                                               else filaAString (columnas-1) (tail fila) (acc++ " "++show(head fila)) 

instance Show Matriz where
 show (M (filas,columnas,matriz)) = matrizAString filas columnas matriz []

--3
--CUIDADO: Cuando el texto tiene caracteres especiales como tildes o eñes da problemas y no queda perfectamente justificado porque las tildes/eñes
--las interpreta como 2 caracteres y entonces esas líneas no están justificadas sino que están metidas una columna (por caracter especial) hacia la izquierda

formatea :: String -> String -> Int -> IO()
formatea fileIn fileOut n = do texto <- readFile fileIn
                               writeFile fileOut (formateaTexto (lines texto) n "")

formateaTexto :: [String] -> Int ->  String -> String
formateaTexto lineas n acc = if length(lineas) == 0 then acc
                                                    else formateaTexto (tail lineas) n (acc++(formateaLinea (head lineas) n)++"\n")

formateaLinea :: String -> Int ->  String
formateaLinea linea n = formateaLineaUnSoloEspacio (unwords(words linea)) n

formateaLineaUnSoloEspacio :: String -> Int -> String
formateaLineaUnSoloEspacio linea n = if (length linea)>=n then linea
                                                         else meterEspacios (words linea) (length (words linea)) (n-(length (concat (words linea))))

meterEspacios ::[String]-> Int -> Int ->String
meterEspacios palabras numPalabras numEspaciosPorMeter = if numPalabras == 0 then ""
                                                         else if numPalabras == 1 then ((head palabras) ++[' '|x<-[1..numEspaciosPorMeter]])
                                                         else ((head palabras) ++ [' '|x<-[1..numPrimEspac]] ++ (meterEspacios (tail palabras) (numPalabras-1) (numEspaciosPorMeter-numPrimEspac)))
                                                         where numPrimEspac = ceiling((fromIntegral numEspaciosPorMeter)/ (fromIntegral (numPalabras-1)))::Int
