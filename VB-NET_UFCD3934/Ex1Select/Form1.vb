Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim Valor As Single

        Valor = TextBox1.Text

        Select Case Valor
            Case 0 To 49
                lblClassifica.Text = "Prova de Recuperação"
            Case 50 To 59
                lblClassifica.Text = "Suficiente"
            Case 60 To 69
                lblClassifica.Text = "Bom"
            Case 70 To 79
                lblClassifica.Text = "Muito Bom"
            Case 80 To 100
                lblClassifica.Text = "Excelente"
            Case Else
                lblClassifica.Text = "Error 404!! Insira os valores entre 0-100!"
        End Select
    End Sub

    Private Sub btnAtendimento_Click(sender As Object, e As EventArgs) Handles btnAtendimento.Click
        Dim nFila As Integer

        nFila = TextBox2.Text

        Select Case nFila
            Case 1
                MessageBox.Show("Você será o próximo atendido")
            Case 2 To 5
                MessageBox.Show("Você será atendido em breve")
            Case 6, 7, 8
                MessageBox.Show("Seu tempo de espera poder ser demorado")
            Case Else
                MessageBox.Show("Você não será atendido hoje")

        End Select

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Dim vlEuro As Decimal

        If Decimal.TryParse(txtEuro.Text, vlEuro) Then
            Dim resultado As Decimal

            Select Case ComboBox1.SelectedItem
                Case "USD"
                    resultado = vlEuro * 1.16
                Case "GBP"
                    resultado = vlEuro * 0.84
                Case "BRL"
                    resultado = vlEuro * 6.25
                Case Else
                    MessageBox.Show("Selecione uma moeda válida")
            End Select
            lblCambio.Text = "O Resultado da Conversão é: " & resultado & ComboBox1.SelectedItem

        End If
    End Sub
End Class
