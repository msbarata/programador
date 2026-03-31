Imports System.Windows.Forms.VisualStyles.VisualStyleElement

Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Const Valor_hora As Double = 35.0 'valor contante de mão de obra

        Dim horas As Double = CDbl(txtHoras.Text)
        Dim MObra As Double = Valor_hora * horas
        Dim Pecas As Double = CDbl(txtCusto.Text)


        Dim CustoTotal As Double = MObra + Pecas 'Variavel para calcular custo orçamento

        ListBox1.Items.Clear()

        'dados para aparecerem na Listbox

        ListBox1.Items.Add("Nome do Cliente: " & txtNome.Text)

        ListBox1.Items.Add("O Valor da Mão de Obra é: " & MObra.ToString("C"))
        ListBox1.Items.Add("O Valor das Peças é: " & Pecas.ToString("C"))

        ListBox1.Items.Add("O total a pagar: " & CustoTotal.ToString("C"))

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        ListBox1.Items.Clear()
        txtHoras.Text = ""
        txtCusto.Text = ""
        txtNome.Text = ""

        txtNome.Focus()
    End Sub
End Class
