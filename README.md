# Requisitos mínimos:
 
Nivel 1: Documentación completa + mantenimientos (opciones 1 y 2 del menú) funcionando correctamente. (sobre 5 Puntos).

Nivel 2: Apartado anterior + 3 funcionando al 100% (opción 3 del menú) (sobre 7 puntos). 

Nivel 3: Apartados anteriores + 4 funcionando al 100% (opción 4 del menú) (sobre 8 puntos).

Nivel 4: Los apartados anteriores + funcionalidades adicionales (bajas, informes extra a parte de los que se piden,consultas) (sobre 9 puntos)

- Calidad de la documentación y presentación (aspecto de las pantallas, diseño de informes, etc...) 1 Punto adicional.

La calidad de la documentación y el diseño puntuarán siempre 1 punto adicional.

Temporización recomendada:

Apartados 1 y 2: 2 de mayo.

Apartado 3: 15 de mayo.

Apartado 4: 31 de mayo.

Documentación: final de curso.




PRACTICA  DE  LENGUAJE  C  EN  Windows.





Una empresa desea mecanizar, en parte, su proceso de facturación de la siguiente forma:

•	Introducirá los datos de sus clientes.
•	Introducirá los datos de sus servicios.
•	Introducirá diariamente, los presupuestos aceptados por sus clientes.
•	Al final de la semana desea que se le faciliten las facturas correspondientes a los servicios realizados durante la semana y un listado resumen de la facturación.

Para implementar esta simple mecanización  procederemos como sigue:

Escribiremos UN MAIN para sacar el menú en pantalla y llamar a ejecutar el programa correspondiente a cada opción:


MENU DE FACTURACION

1  Clientes
2  Servicios
3  Presupuestos
4  Facturación
5  Salir







 
PROGRAMA DE CLIENTES:

 

	FICHERO  DE  CLIENTES: 	
	DATO	CAMPO	TIPO	TAMAÑO	
	Nº Cliente		int		
	Nombre		char	20	
	Domicilio		char	20	
	Código Postal		char	5	
	Municipio		char	15	
	N.I.F.		char	10	


	PANTALLAS  DEL  PROGRAMA:
	
	FICHERO DE CLIENTES
	
	Nº Cliente	:  xxx
	
	Nombre	:  xxxxxxxxxxxxxxxxxxxx
	
	Domicilio	:  xxxxxxxxxxxxxxxxxxxx
	
	Cod. Postal	:  xxxxx
	
	Municipio	:  xxxxxxxxxxxxxxx
	
	N.I.F.	:  xxxxxxxxxx
	
	
(Línea de mansajes)
	


	MENU  DE  CLIENTES
	
	1  ALTAS
	
	2  MODIFICAR
	
	3  CONSULTAR
	
	4  SALIR
	
		


PSEUDOCÓDIGO:

Sacar el menu en pantalla y pedir opción.
Hacer mientras no tecleeen la opción de salir.
	Si opción es 1:
		Mirar si existe el fichero.
		Calcular nº del último registro grabado.
		Abrir fichero para añadir registros
		Sacar pantalla de petición de datos y nº del siguiente cliente
		Pedir resto de los datos
		Pedir conformidad y grabar si está conforme.
		Cerrar el fichero y salir al menú
	Si opción es 2:
		Mirar si existe el fichero.
		Calcular nº del último registro grabado.
		Abrir fichero para leer 
		 Sacar pantalla de datos y pedir Nº Cliente
		Si el Nº Cliente está dentro de los límites 
			Visualizar el resto de los datos
			Pedir datos a modificar
			Pedir conformidad y regrabar si está conforme
		Si no está dentro de los límites, mensaje de error
		Cerrar el fichero y salir al menú
	Si opción es 3:
		Mirar si existe el fichero.
		Calcular nº del último registro grabado.
		Abrir fichero para leer 
		 Sacar pantalla de datos y pedir Nº Cliente
		Si el Nº Cliente está dentro de los límites 
			Visualizar el resto de los datos
			Pedir continuar 
		Si no está dentro de los límites, mensaje de error
		Cerrar el fichero y salir al menú
Fin de Hacer mientras

 
PROGRAMA DE SERVICIOS:

 

	FICHERO  DE  SERVICIOS: 	
	DATO	CAMPO	TIPO	TAMAÑO	
	Nº Servicio		int		
	Denominación		char	20	
	Precio Coste		int		
	P.V.P. 	Precio/hora	int		


	PANTALLAS  DEL  PROGRAMA:
	
	FICHERO DE SERVICIOS
	
	Nº Servicio	:  xxx
	
	Denominación	:  xxxxxxxxxxxxxxxxxxxx
	
	Precio Coste	:  xx.xxx
	
	P.V.P.	:  xx.xxx
	
	



(Línea de mansajes)
	


	MENU  DE  SERVICIOS
	
	1  ALTAS
	
	2  MODIFICAR
	
	3  CONSULTAR
	
	4  SALIR
	
		

 
PSEUDOCÓDIGO:

Sacar el menu en pantalla y pedir opción.
Hacer mientras no tecleeen la opción de salir.
	Si opción es 1:
		Mirar si existe el fichero.
		Calcular nº del último registro grabado.
		Abrir fichero para añadir registros
		Sacar pantalla de petición de datos y nº del siguiente servicio
		Pedir resto de los datos
		Pedir conformidad y grabar si está conforme.
		Cerrar el fichero y salir al menú
	Si opción es 2:
		Mirar si existe el fichero.
		Calcular nº del último registro grabado.
		Abrir fichero para leer 
		 Sacar pantalla de datos y pedir Nº servicio
		Si el Nº servicio está dentro de los límites 
			Visualizar el resto de los datos
			Pedir datos a modificar
			Pedir conformidad y regrabar si está conforme
		Si no está dentro de los límites, mensaje de error
		Cerrar el fichero y salir al menú
	Si opción es 3:
		Mirar si existe el fichero.
		Calcular nº del último registro grabado.
		Abrir fichero para leer 
		 Sacar pantalla de datos y pedir Nº Servicio
		Si el Nº Servicio está dentro de los límites 
			Visualizar el resto de los datos
			Pedir continuar 
		Si no está dentro de los límites, mensaje de error
		Cerrar el fichero y salir al menú
Fin de Hacer mientras

 
PROGRAMA  DE  PRESUPUESTOS:


 


	FICHERO  DE  PRESUPUESTOS: 	
	DATO	CAMPO	TIPO	TAMAÑO	
	Nº Cliente		int		
	Nº SERVICIO		int		
	P.V.P.		int		
	Horas 		float		


PANTALLA  DEL  PROGRAMA:

	FICHERO DE PRESUPUESTOS
	
	Nº Cliente: xxxx      xxxxxxxxxxxxxxxxxxx
	
	Nº Servicio	Denominación	P.V.P.	Cantidad	
		

			
		

			
		



(línea de mensajes)			

 
PSEUDOCÓDIGO:


Si no existen los ficheros de Clientes y Servicios, mensaje de error y fin de programa .
Calcular nº del último registro grabado en los ficheros de Clientes y Servicios.
Abrir ficheros: Clientes y Servicios de lectura y Presupuestos para añadir registros.
Sacar pantalla de petición de datos.
Pedir Nº Cliente.
Hacer mientras Nº Cliente sea distinto de 0
	Si no está dentro de los límites, mensaje de error
	Si está dentro de los límiltes:
		Leer el registro y sacar nombre
		Pedir Nº Servicio
		Hacer mientras Nº Servicio sea distinto de 0
			Si no está dentro de los límites, mensaje de error
			Si está dentro de los límites:
				Leer registro
				Visualizar Denominación y P.V.P.
				Pedir cantidad
				Pedir conformidad y grabar en presupuestos si está conforme
			Pedir Nº Servicio
		Fin hacer servicios
	Pedir Nº Cliente
Fin hacer clientes.
Cerrar ficheros y salir a menú


 
PROGRAMA  DE  FACTURACIÓN:

  




	FICHERO  DE  RESUMEN: 	
	DATO	CAMPO	TIPO	TAMAÑO	
	Nº Factura		int		
	Nº Cliente		int		
	Base Imponible		float		
	IVA		float		


 
DISEÑOS  DE  LISTADOS:



FACTURA;

				
		Nombre
Domicilio
C.P.  Municipio
				
Fecha:		Nº Factura:		
Nº Servicio	Denominación	P.V.P.	Cantidad	Importe
				
				
				
				
				
				
				
				
				
				
				
				
				
			Base Imp.	
			IVA	
			TOTAL	
				


INFORME RESUMEN FACTURACIÓN:


LISTADO RESUMEN DE FACTURACIÓN DEL dd-mm-aa

Nº Factura	Cliente	N.I.F.	Base Imponible	IVA
				
				
				
				
				
				
				
		TOTALES		

 
PSEUDOCÓDIGO:

Si no existe el fichero de presupuestos, mensaje de error y fin de programa.
Abrir los ficheros de Clientes, Servicios y Presupuestos de lectura y el fichero resumen de grabación.
Pedir Nº de factura de comienzo.
Leer Presupuestos
Hacer mientras no sea fin de Presupuestos
	Leer Cliente 
	Sacar cabecera de factura
	Hacer mientras no sea fin de Presupuestos y no cambie de cliente
		Leer Servicio.
		Calcular importe
		Imprimir línea de detalle
		Sumar importe a Base Imponible
		Leer Pedido
	Fin hacer cliente
	Imprimir Base Imponible
	Calcular Iva e imprimir
	Sumar Base Imponible + IVA e imprimir
	Grabar un registro en Resumen
Fin hacer Presupuestos
Cerrar Resumen
Abrir Resumen para leer
Sacar cabecera del informe resumen
Leer Resumen
Hacer mientras no sea fin de Resumen
	Leer Cliente
	Imprimir línea de detalle
	Acumular a totales
	Leer Resumen
Fin hacer resumen
Imprimir totales
Cerrar los ficheros y salir a menú

Documentación a entregar:
•	Código fuente: archivo.
•	Memoria: descripción del programa, descripción de cada una de las partes y las consideraciones hechas al enunciado.
•	Manual de usuario: Descripción del manejo de la aplicación.
•	Diagramas de flujo. De todos los programas y funciones realizados.

