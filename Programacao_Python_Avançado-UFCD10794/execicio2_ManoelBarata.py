import os 

# EXERCÍCIO 2 — UFCD 10793 - Programa de orçamentação de serviços de casa

# SUPERCLASSE — é o "molde geral" de qualquer serviço de casa. As subclasses (telhado, pintura) vão herdar tudo o que nela for definido.

class Servico_Casa:

  
    # ATRIBUTO DE CLASSE  - total_servicos_criados - (estático): Imagina uma folha de papel colada na parede da sala (a classe). 
    # Os objetos criados olham para essa mesma folha. Cada vez que nasce um novo serviço, o número nessa folha é incrementado em 1.
    # Trata-se de um atributo que não pertence a nenhum objeto em particular — pertence à CLASSE inteira.
   
    total_servicos_criados = 0          # contador partilhado por TODOS os objetos


    # __init__ — "ficha de nascimento" de cada objeto. Este é chamado automaticamente quando escrevemos, por exemplo:
    #  t = ReparacaoTelhado("EmpresaX", 50)
 
    def __init__(self, nome_servico, empresa, area, valor_m2):

         # ATRIBUTO PRIVADO  (__area e __empresa) - O duplo underscore (__) é como um cadeado na gaveta.
         # Ninguém de fora da classe consegue escrever  objeto.__area  diretamente.
         # Para VER o valor usamos get_area(); para ALTERAR o valor usamos set_area();  
         # Útil para proteger as áreas dos atributos contra alterações acidentais ou inválidas.

        self.nome_servico = nome_servico    # atributo público — qualquer um lê
        self.__empresa      = empresa        # PRIVADO — só acessível dentro desta classe
        self.valor_m2     = float(valor_m2) # atributo público — qualquer um lê
        self.__area = float(area)           # PRIVADO — só acessível dentro desta classe

        # Uso do método estático de classe - cada vez que um objeto nasce, incrementamos o contador da classe
        Servico_Casa.total_servicos_criados += 1

   
    # USO do GETTER (método público para LER o atributo privado) 
    # Como a gaveta está fechada, criamos uma "janela de vidro" para se ver
    # o valor sem poder mexer diretamente nele.
    # Uso:  t.get_area() - devolve o número guardado em __area
    # Uso:  t.get_empresa() - devolve o número guardado em __empresa
    
    def get_area(self):
        return self.__area
    

    def get_empresa(self):
        return self.__empresa


    # USO do SETTER (método público para ALTERAR o atributo privado)
    
    # Se queremos mudar o valor dentro da gaveta fechada, usamos este método. 
    # Ele valida primeiro: se o valor for negativo ou zero, recusa a alteração.
    # Uso:  t.set_area(80)  - altera __area para 80 (se for positivo)
    
    def set_area(self, nova_area):
        if nova_area <= 0:
            print("Erro: a área tem de ser positiva.")
            return                          # sai sem alterar nada
        self.__area = float(nova_area)      # só chega aqui se o valor for válido


    # Método base de cálculo — será SUBSTITUÍDO pelas subclasses.
    # Por enquanto faz: área × preço por m².

    def calcula_valor_total(self):
        return self.get_area() * self.valor_m2


    # Método base de tempo — OBRIGA as subclasses a implementar a sua versão.
    # Se uma subclasse não o sobrescrever e alguém o chamar, Python lança erro.
  
    def calcular_tempo_reparo(self):
        raise NotImplementedError(
            f"A subclasse '{type(self).__name__}' deve implementar "
            "calcular_tempo_reparo()."
        )
  
    # Este método 'def resumo' representa o polimorfismo, pois está definido UMA SÓ VEZ aqui na superclasse.
    # No entanbto, dentro dele chamamos calcula_valor_total() e calcular_tempo_reparo(), para dois objetos distintos.
    # Se o objeto for um ReparacaoTelhado, Python usa os métodos do telhado; por outro lado,
    # Se o objeto for um PinturaCasa, Python usa os métodos da pintura. Assim, O mesmo código (resumo) comporta-se de forma DIFERENTE,
    # conforme o objeto. Não precisamos escrever dois resumos — escrevemos um e ele adapta-se!
   
    # Estas linhas abaixo, chamam seus respetivos métodos; recebe e formata os valores devolvidos; mostra resultado na tela.
    # f"{ }" — f-string: permite incorporar código Python diretamente no texto. O :.1f dentro de { } é a formatação do número.
    def resumo(self):
        print("=" * 50)
        print(f"  Serviço        : {self.nome_servico}")
        print(f"  Empresa        : {self.get_empresa()}")   # Uso do método GETTER para aceder a atributos privados.
        print(f"  Área           : {self.get_area():.1f} m²") # Uso do método GETTER para aceder a atributos privados.
        print(f"  Valor por m²   : {self.valor_m2:.2f} €")
        print(f"  Custo total    : {self.calcula_valor_total():.2f} €")   # polimorfismo - mesmo nome de método & comportamento diferente conforme a subclasse do objeto.
        print(f"  Tempo estimado : {self.calcular_tempo_reparo():.1f} semanas")  # polimorfismo - mesmo nome de método & comportamento diferente conforme a subclasse do objeto.
        print(f"  Serviços criados: {Servico_Casa.total_servicos_criados}") 
        print("=" * 50)


    # USO do MÉTODO ESTÁTICO  (@staticmethod)
    # Um método normal recebe sempre self (o próprio objeto). Um método estático NÃO recebe self, pois não pertence a nenhum objeto.
    # Estes pertencem à CLASSE toda. Assim, Métodos Estáticos podem ser chamados de duas formas equivalentes:
    # Servico_Casa.contar_servicos() - sendo chamado por intermédio da própria CLASSE (Servico_Casa.)
    # ou poderá ser chamado por qualquer_objeto desta mesma classe - (Servico_Casa.)

    @staticmethod
    def contar_servicos():
        print(f"Total de serviços criados: {Servico_Casa.total_servicos_criados}")


# SUBCLASSE — Reparação de Telhado: Herda tudo da SUPERCLASSE Servico_Casa e SOBRESCREVE (overrides) dois métodos:
# calcula_valor_total()  &  calcular_tempo_reparo()  - (lógica própria do ReparaçãoTelhado)
# Isto é o POLIMORFISMO: uso da mesma "assinatura" de método, para comportamento diferente.

class ReparacaoTelhado(Servico_Casa):                   #Subclasse ReparacaoTelhado - indica a superClasse à que pertence, entre parênteses.

    _tempo_por_m2    = 0.12         # 0,12 semanas por cada m² de telhado - (valor default)
    VALOR_M2_PADRAO  = 35.00        # preço fixo — Reparação do Telhado - (valor default)


    def __init__(self, empresa, area):
        # super() chama o __init__ da superclasse Servico_Casa,
        # passando o nome fixo do serviço e o preço default pelo M2 da reparacao.
        super().__init__("Reparação de Telhado", empresa, area, ReparacaoTelhado.VALOR_M2_PADRAO)


    # Por meio do  POLIMORFISMO, Quando resumo() chamar calcula_valor_total() para ReparacaoTelhado, este usará o método da superclasse.
 
    # Por meio do  POLIMORFISMO, este método SOBRESCREVE o da superclasse, pois são diferentes (0.08 vs 0.12) - fica em cada subclasse.
    # Utiliza esta fórmula específica para telhado: área × 0,12 semanas/m²
    def calcular_tempo_reparo(self):
        return self.get_area() * self._tempo_por_m2


# SUBCLASSE — Pintura de Casa: Igual à lógica acima, mas com valores próprios da pintura.
# # calcula_valor_total()  &  calcular_tempo_reparo()  - (lógica própria do PinturaCasa)
# O polimorfismo garante que resumo() funciona do mesmo modo para ambas.


class PinturaCasa(Servico_Casa):   #Subclasse PinturaCasa - indica a superClasse à que pertence, entre parênteses.

    _tempo_por_m2    = 0.08         # pintura é mais rápida: 0,08 semanas por m² - (valor default)
    VALOR_M2_PADRAO  = 12.00        # preço fixo da pintura é mais barato - (valor default)


    def __init__(self, empresa, area):
        # super() chama o __init__ da superclasse Servico_Casa.
        # passando o nome fixo do serviço e o preço default pelo M2 da Pintura.

        super().__init__("Pintura de Casa", empresa, area, PinturaCasa.VALOR_M2_PADRAO)


 # Por meio do  POLIMORFISMO, Quando resumo() chamar calcula_valor_total() para PinturaCasa, este usará o método da superclasse.

 # Por meio do  POLIMORFISMO, este método SOBRESCREVE o da superclasse, pois são diferentes (0.08 vs 0.12) - fica em cada subclasse.
    # Utiliza esta fórmula específica para telhado: área × 0,08 semanas/m²
    def calcular_tempo_reparo(self):
        return self.get_area() * self._tempo_por_m2


# FUNÇÕES AUXILIARES
# Este método funciona para validar as entradas de valores numericos decimais pelo utilizadores.
def pedir_float(mensagem):
    """Continua a pedir um número ao utilizador até receber um valor válido."""
    while True:
        try:
            valor = float(input(mensagem))
            if valor <= 0:
                print("  O valor tem de ser positivo. Tente novamente.")
            else:
                return valor
        except ValueError:
            print("  Entrada inválida. Introduza um número.")


# FUNÇÃO PRINCIPAL (MAIN)
# Este é o método principal e inicial do programa, que permite a inserção dos dados por parte dos utilizadores;
#

def main():
    print("=" * 50)
    print("   Bem-vindo ao Sistema de Serviços de Casa")
    print("=" * 50)

    nome_utilizador = input("Por favor, introduza o seu nome: ").strip()
    if not nome_utilizador:
        nome_utilizador = "Utilizador"
    
    os.system("cls" if os.name == "nt" else "clear")  # ← limpa o ecrã 
    
    # Loop principal (While True) — repete o menu até o utilizador escolher 0
    # Mostra na tela as duas opções, nas quais o utilizador poderá escolher ou 0 para sair.
    # Cada uma das opções (1 & 2) acedem e mostram o atributo de classe VALOR_M2_PADRAO das respetivas subclasses: (ReparacaoTelhado/PinturaCasa)

    while True:

        print(f"""
==== Menu Principal ====
  Olá, {nome_utilizador}!  
  1 - Orçamentar & Estimar tempo de conclusão - Reparação de Telhado  ({ReparacaoTelhado.VALOR_M2_PADRAO:.2f} €/m²)
  2 - Orçamentar & Estimar tempo de conclusão - Pintura  ({PinturaCasa.VALOR_M2_PADRAO:.2f} €/m²)
  0 - Sair
""")

        opcao = int(input("Escolha uma das seguintes opções [1, 2 ou 0 para sair]: "))

        if opcao == 1:
            # Criamos um objeto ReparacaoTelhado e chamamos resumo().
            # O resumo() está na superclasse mas chama os métodos Desta subclasse.
            empresa = input("  Nome da empresa: ")
            area    = pedir_float("  Área do telhado (m²): ")   #Usa método para validar dado numérico decimal inserido
            
            # Criamos um objeto (instância) da subclasse ReparacaoTelhado. É como preencher uma ficha de serviço
            # com os dados introduzidos pelo utilizador, empresa=empresa, area=area.
            # A partir deste momento, a variável 't'  dá-nos acesso a todos os métodos, da classe ReparacaoTelhado.
            t = ReparacaoTelhado(empresa=empresa, area=area)

            print()
            t.resumo()                          # polimorfismo: usa métodos do telhado

             # Por intermédio dos métodos getter e setter dados podem ser acedidos & alterados pelo utilizador
             # f"{ }" — f-string: permite incorporar código Python diretamente no texto. O :.1f dentro de { } é a formatação do número.
            print(f"\n  Área atual (getter): {t.get_area():.1f} m²")
            nova = pedir_float("  Alterar área? Introduza o novo valor (m²): ")    #Usa método para validar dado numérico decimal inserido
            t.set_area(nova)                    # setter: altera o atributo privado
            print(f"  Nova área (após setter): {t.get_area():.1f} m²")
            print("\n  Resumo atualizado:")
            t.resumo()

            Servico_Casa.contar_servicos()      # Uso do método estático da classe para chamar contador de objetos criados

        elif opcao == 2:
            # Criamos um objeto PinturaCasa e chamamos resumo().
            # O resumo() está na superclasse mas chama os métodos desta subclasse.
            empresa = input("  Nome da empresa: ")
            area    = pedir_float("  Área das paredes (m²): ") 

            # Criamos um objeto (instância) da subclasse PinturaCasa. É como preencher uma ficha de serviço
            # com os dados introduzidos pelo utilizador, empresa=empresa, area=area.
            # A partir deste momento, a variável 'p'  dá-nos acesso a todos os métodos, da classe PinturaCasa.
            p = PinturaCasa(empresa=empresa, area=area)

            print()
            p.resumo()                          # polimorfismo: usa métodos da pintura

            # Por intermédio dos métodos getter e setter dados podem ser acedidos & alterados pelo utilizador
            # f"{ }" — f-string: permite incorporar código Python diretamente no texto. O :.1f dentro de { } é a formatação do número.
            print(f"\n  Área atual (getter): {p.get_area():.1f} m²")
            nova = pedir_float("  Alterar área? Introduza o novo valor (m²): ")
            p.set_area(nova)                    # setter: altera o atributo privado
            print(f"  Nova área (após setter): {p.get_area():.1f} m²")
            print("\n  Resumo atualizado:")
            p.resumo()

            Servico_Casa.contar_servicos()      # Uso do método estático da classe para chamar contador de objetos criados

        elif opcao == 0:
            print(f"\nAté à próxima, {nome_utilizador}! Volte sempre!\n")
            break   # sai do while True e termina o programa

        else:
            print("  Opção inválida. Por favor escolha 1, 2 ou 0.")

# Ponto de entrada — só corre o main() se este ficheiro for executado diretamente
if __name__ == "__main__":
   main()