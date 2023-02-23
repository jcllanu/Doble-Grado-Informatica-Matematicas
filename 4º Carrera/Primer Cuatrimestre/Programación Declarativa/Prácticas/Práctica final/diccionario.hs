--Juan Carlos Llamas Núñez 4ºDG Mat-Inf

-- 1.- Definición de una estructura de datos de nombre Hash para representar una tabla hash.

-- Hay dos alternativas a la hora de plantear la estructura interna de la tabla Hash. La primera de ellas es hacer una 10-tupla de listas y la segunda
-- es estructurarlo como una lista de listas y limitar internamente que la lista externa tenga exactamente 10 elementos (que serán a su vez listas, 
-- estas últimas de tamaño variable). Nos decidimos por la segunda posibilidad ya que consideramos que frente a posibles cambios sobre el número de índices
-- de la tabla Hash es mucho más sencillo modificar la segunda opción. Por ello la estructura de datos interna contendrá un entero que indique el número de
-- índices de la que dispone la Tabla Hash y una lista de listas de pares (String, String)

data Hash = H (Int, [[(String,String)]])

-- 2.-Declaración del tipo Hash como instancia de la clase Show, mediante redefinición del método show

-- Las filas de la tabla se construyen como elementos de una lista instensional. Estos elementos están encabezados con el número de índice, y seguidos por
-- el resultado de llamar a la función auxiliar mostrarFila con el elemento i-ésimo de la tabla, es decir, la fila i-ésima. La función auxiliar mostrarFila
-- simplemente da un formato adecuado a la lista de pares (String,String) convirtiéndolas en Strings y juntándolas con la función unwords.
-- Ejemplo: [("Hola","Hello"),("Adios","Bye")] ::[(String,String)] se convierte en "(Hola,Hello) (Adios,Bye)"::String
-- Por último cabe destacar que, una vez tenemos la lista intensional formada por cada una de las listas que queremos mostrar, simplemente hay que aplicarle
-- la función unlines para obtener el formato deseado y añadirle unos delimitadores superiores e inferiores.

instance Show Hash where
 show (H (numIndices,tabla)) = "\n---\n"++(unlines ["|"++(show i)++"|->"++(mostrarFila (tabla!!i))|i<-[0..numIndices-1]])++"---\n"

mostrarFila :: [(String,String)]-> String
mostrarFila fila = unwords (map (\(x,y)-> "("++x++","++y++")") fila)

--3.-Definición de la función hash. Dada una palabra en español devuelve su valor en el índice de la tabla. El índice tiene solo 10 valores distintos.

-- Como primera versión y para facilitar la depuración vamos a utilizar como valor de hash la longitud de la palabra módulo 10 (se dice que no es importante
-- y no tiene porqué ser eficiente).
-- Utilizamos una constante entera numeroIndices con valor 10 que representa el número de índices que va a tener nuestra tabla hash. 

numeroIndices :: Int
numeroIndices = 10

hash :: String -> Int
hash palabra= mod (length palabra) numeroIndices

--4.-Inicialización del diccionario. Rellena la tabla hash donde se almacenará el diccionario a partir del fichero de texto dado datos.txt

-- En primer lugar leemos el fichero de texto datos.txt con la función readFile y construimos nuestra estructura de datos Hash haciendo uso de la función
-- auxiliar annadirPalabras.

inicializar :: IO Hash
inicializar = do x <- readFile "datos.txt"
                 return (H (numeroIndices, annadirPalabras hashvacia (lines x)))

-- La función auxiliar annadirPalabras añade una lista de lineas (en cada linea debe haber dos palabras separadas por un espacio que representan una
-- palabra y su traducción) a una lista de lista de pares (String,String) que representa la tabla hash. Para ello necesitamos separar en lineas el 
-- contenido del fichero datos.txt y crear una estructura Hash vacía. Esto último se puede conseguir fácilmente con una lista intensional que será
-- una lista formada por numeroIndices listas vacías (de tipo(String,String)).

hashvacia :: [[(String,String)]]
hashvacia =[[]|i<-[0..numeroIndices-1]]


-- La función auxiliar annadirPalabras devuelve la tabla dada si el número de líneas a añadir es cero y, si no, añade las líneas de forma recursiva 
-- haciedndo uso de una segunda función auxiliar insertarPalabraEnTabla

annadirPalabras :: [[(String,String)]] -> [String] -> [[(String,String)]]
annadirPalabras tabla [] = tabla
annadirPalabras tabla palabras = annadirPalabras nuevatabla (tail palabras) where nuevatabla = insertarPalabraEnTabla tabla ((\xs->(head xs, head (tail xs)))(words(head palabras)))

-- La función insertarPalabraEnTabla recibe una tabla Hash en fromato lista de lista de pares de String y un nuevo par de Strings a añadir. Devuelve
-- el resultado de haber añadido a la tabla el par en el sitio correcto, es decir, en la fila correspondiente a su índice según la función hash.
-- La implementación se puede hacer de forma sencilla con listas intensionales, creando cada fila de la nueva tabla hash a partir de la anterior y
-- teniendo en cuenta que en la fila asociada al índice de la nueva palabra añadida hay que añadir un nuevo par.

insertarPalabraEnTabla :: [[(String,String)]] -> (String,String) -> [[(String,String)]]
insertarPalabraEnTabla tabla (espanol,traduccion) = [if i==(hash espanol) then ((tabla!!i) ++ [(espanol,traduccion)]) else (tabla!!i) |i<-[0..numeroIndices-1]]

--5.- Lectura de varias palabras a traducir introducidas por el teclado.
--6.- Cálculo de la longitud media de las palabras introducidas.
--7.- Búsqueda en el diccionario de la traducción de las palabras introducidas.
--8.- Muestra en pantalla la traducción de las palabras en el orden en el que se introdujeron o un mensaje para aquellas que no aparecen en el diccionario

-- Implementamos toda esta funcionalidad en una única funcion usarDiccionario
usarDiccionario :: IO ()
usarDiccionario = do putStrLn "\nHola, bienvenid@ al diccionario Español-Inglés de Programación Declarativa."
                     putStrLn "El modo de uso es el siguiente: introduce una serie de palabras (separadas por un espacio) en español para traducirlas a inglés."
                     putStrLn "Por ejemplo: hoja pereza malicioso\n"
                     line <- getLine
                     putStrLn ("\nLa longitud media de las palabras que has introducido es " ++ (show (longitudMedia (words line)))++".")
                     putStrLn "\nA continuación se muestra la traducción de cada una de estas palabras:\n"
                     diccionario <- inicializar 
                     putStrLn (traducirPalabras diccionario (words line))

-- La función longitudMedia calcula la longitud media de la lista de palabras que se le pasa como argumento y devuelve esta media como un Float

longitudMedia :: [String] -> Float
longitudMedia palabras = fromIntegral(sum (map length palabras))/fromIntegral(length palabras)

-- La función traducirPalabras recibe la lista de palabras a traducir y el diccionario y devuelve su traducción en formato String y de la forma que van a ser 
-- impresas por pantalla. Funciona de manera recursiva, traduciendo las palabras de una a una y para ello utiliza otra función auxiliar traducirPalabra.

traducirPalabras :: Hash -> [String] -> String
traducirPalabras _ [] = ""
traducirPalabras diccionario palabras = traducirPalabra diccionario (head palabras) ++ traducirPalabras diccionario (tail palabras)

-- La función traducirPalabra recibe la tabla Hash y la palabra a traducir y devuelve la traducción de esa palabra, es decir, una línea con la palabra
-- y su traducción o un mensaje de que la palabra no se encuentra en el diccionario. Llama a su vez a la función buscar que recibe en sus argumentos no 
-- toda la tabla Hash sino que únicamente la fila de la tabla hash cuyo índice coincide con el valor de la función de hash para la palabra a buscar.

traducirPalabra :: Hash -> String -> String
traducirPalabra (H (numIndices, tabla)) palabra = buscar (tabla!!(hash palabra)) palabra

-- La función buscar es muy sencilla porque simplemente recorre la lista que se le pasa como argumento de manera recursiva de izquierda a derecha y
-- comparando si el primer elemento de cada tupla coincide con la palabra a traducir. En caso afirmativo, el segundo elemento de la tupla es la traducción
-- y si no es así pasa al siguiente par de la lista. Si al llegar al final no se ha encontrado la traducción es que esta palabra no está en nuestro
-- diccionario y se manda un mensaje de error. No puede suceder que esté en otra fila de la tabla hash porque se tiene que encontrar en la fila que 
-- tiene como índice el valor de la función hash para esa palabra. 

buscar :: [(String,String)]->String->String
buscar [] palabra = "Lo sentimos, la traducción de la palabra " ++ palabra ++ " no se encuentra actualmente en nuestro diccionario.\n"
buscar ((x,y):xs) palabra
          |x==palabra       = palabra ++ " <=> "++y++"\n"
          |otherwise        = buscar xs palabra