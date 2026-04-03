from graphviz import Graph

# Criar diagrama ER no estilo Chen (entidade-relacionamento)
er_chen = Graph("ER_Chen", format="png")
er_chen.attr(rankdir="LR", size="10")

# ================== Entidades ==================
# Fonte
er_chen.node("Fonte", shape="rectangle")
er_chen.node("id_fonte", shape="ellipse", style="bold", label="id_fonte (PK)")
er_chen.node("nome_fonte", shape="ellipse", label="nome")
er_chen.node("url_api", shape="ellipse", label="url_api")
er_chen.node("tipo_fonte", shape="ellipse", label="tipo")
er_chen.edges([("Fonte", "id_fonte"), ("Fonte", "nome_fonte"), ("Fonte", "url_api"), ("Fonte", "tipo_fonte")])

# Recurso
er_chen.node("Recurso", shape="rectangle")
er_chen.node("id_recurso", shape="ellipse", style="bold", label="id_recurso (PK)")
er_chen.node("titulo_recurso", shape="ellipse", label="título")
er_chen.node("descricao_recurso", shape="ellipse", label="descrição")
er_chen.node("tipo_recurso", shape="ellipse", label="tipo")
er_chen.node("link_original", shape="ellipse", label="link_original")
er_chen.node("id_fonte_FK", shape="ellipse", style="dashed", label="id_fonte (FK)")
er_chen.edges([("Recurso", "id_recurso"), ("Recurso", "titulo_recurso"), 
               ("Recurso", "descricao_recurso"), ("Recurso", "tipo_recurso"), 
               ("Recurso", "link_original"), ("Recurso", "id_fonte_FK")])

# Tema
er_chen.node("Tema", shape="rectangle")
er_chen.node("id_tema", shape="ellipse", style="bold", label="id_tema (PK)")
er_chen.node("nome_tema", shape="ellipse", label="nome_tema")
er_chen.edges([("Tema", "id_tema"), ("Tema", "nome_tema")])

# Usuário
er_chen.node("Usuario", shape="rectangle", label="Usuário")
er_chen.node("id_usuario", shape="ellipse", style="bold", label="id_usuario (PK)")
er_chen.node("nome_usuario", shape="ellipse", label="nome")
er_chen.node("email_usuario", shape="ellipse", label="email")
er_chen.edges([("Usuario", "id_usuario"), ("Usuario", "nome_usuario"), ("Usuario", "email_usuario")])

# ================== Relacionamentos ==================
# Fonte - Recurso
er_chen.node("fornece", shape="diamond", label="fornece")
er_chen.edge("Fonte", "fornece")
er_chen.edge("fornece", "Recurso")

# Recurso - Tema (N:N)
er_chen.node("classificado_em", shape="diamond", label="classificado em")
er_chen.edge("Recurso", "classificado_em")
er_chen.edge("classificado_em", "Tema")

# Usuário - Recurso (N:N)
er_chen.node("favorita", shape="diamond", label="favorita")
er_chen.edge("Usuario", "favorita")
er_chen.edge("favorita", "Recurso")

# Recurso - Recurso (auto-relacionamento)
er_chen.node("relacionado_a", shape="diamond", label="relacionado a")
er_chen.edge("Recurso", "relacionado_a")
er_chen.edge("relacionado_a", "Recurso")

# Salvar e renderizar
file_path_chen = "/mnt/data/er_model_chen.png"
er_chen.render(file_path_chen, format="png", cleanup=True)

file_path_chen
