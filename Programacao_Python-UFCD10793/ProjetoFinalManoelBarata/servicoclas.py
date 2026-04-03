
# Classe base genérica (o que seria Servico_Casa)
class Servico_Casa:
    def __init__(self, nome_servico, empresa, valor_mensal, meses_empreitada=3, garantia_meses=12):
        self.nome_servico = nome_servico
        self.empresa = empresa
        self.valor_mensal = float(valor_mensal)
        self.meses_empreitada = meses_empreitada
        self.garantia_meses = garantia_meses

    def calcula_valor_total(self):
        # Lógica base — pode ser sobrescrita pelas subclasses
        return self.meses_empreitada * self.valor_mensal


# Subclasse para telhado (herda de Servico_Casa)
class ReparacaoTelhado(Servico_Casa):
    def __init__(self, empresa, valor_mensal, areaMetro2_telhado, valor_Metro2, 
                 tipo_cobertura="telha", **kwargs):
        super().__init__("Reparação de Telhado", empresa, valor_mensal, **kwargs)
        self.areaMetro2_telhado = float(areaMetro2_telhado)
        self.valor_Metro2 = float(valor_Metro2)
        self.tipo_cobertura = tipo_cobertura
        self.tempo_por_m2 = 0.12

    def calcula_valor_total(self):  # Sobrescreve o método da classe base
        total_mensalidades = self.meses_empreitada * self.valor_mensal
        custo_area = self.areaMetro2_telhado * self.valor_Metro2
        return total_mensalidades + custo_area
    
    def calcular_tempo_reparo(self):
        return self.areaMetro2_telhado * self.tempo_por_m2


# Subclasse para pintura (também herda de Servico_Casa)
class PinturaCasa(Servico_Casa):
    def __init__(self, empresa, valor_mensal, areaMetro2_paredes, valor_Metro2, num_demãos=2, **kwargs):
        super().__init__("Pintura de Casa", empresa, valor_mensal, **kwargs)
        self.areaMetro2_paredes = float(areaMetro2_paredes)
        self.valor_Metro2 = float(valor_Metro2)
        self.num_demãos = num_demãos
        self.tempo_por_m2 = 0.08  # Pintura é mais rápida que telhado

    def calcula_valor_total(self):
        custo_area = self.areaMetro2_paredes * self.valor_Metro2 * self.num_demãos
        return (self.meses_empreitada * self.valor_mensal) + custo_area

    def calcular_tempo_reparo(self):
        return self.areaMetro2_paredes * self.tempo_por_m2


