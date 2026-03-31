Imports System.Drawing
Imports System.Drawing.Printing

Public Class Form1

    ' Variáveis globais para controlo da impressão
    Private dataGridViewPrintRowIndex As Integer = 0
    Private dataGridViewPrintPageNum As Integer = 1
    Private Sub btnCalcular_Click(sender As Object, e As EventArgs) Handles btnCalcular.Click
        DataGridView1.Rows.Clear()
        DataGridView1.Columns.Clear()

        'Variáveis do Formulário

        Dim valorEmprestimo As Double = CDbl(txtValor.Text)
        Dim taxaJuros As Double = CDbl(txtJuros.Text) / 100
        Dim prazoMeses As Integer = CInt(txtPrazo.Text)

        'calcular a prestação

        Dim prestacao As Double = Financial.Pmt(taxaJuros / 12, prazoMeses, -valorEmprestimo)

        'configurar o Datagrid - Para inserir as colunas

        DataGridView1.Columns.Add("Parcela", "Parcela")
        DataGridView1.Columns.Add("Pagamento", "Pagamento")
        DataGridView1.Columns.Add("Juros", "Juros")
        DataGridView1.Columns.Add("Amortização", "Amortização")
        DataGridView1.Columns.Add("Saldo Devedor", "Saldo Devedor")

        'Preencher a Datagridview
        Dim saldoDevedor As Double = valorEmprestimo

        'Variável para acumular os juros
        Dim totalJuros As Double = 0

        For i As Integer = 1 To prazoMeses
            Dim juros As Double = saldoDevedor * (taxaJuros / 12)
            Dim amortizacao As Double = prestacao - juros
            saldoDevedor -= amortizacao

            DataGridView1.Rows.Add(i, prestacao.ToString("C"), juros.ToString("C"), amortizacao.ToString("C"), saldoDevedor.ToString("C"))

            totalJuros += juros 'acumular os juros
        Next

        'mostra pagamento mensal

        lblPrestação.Text = String.Format("{0:C}", prestacao)

        'mostra total em pagamento
        lblTotalPagamentos.Text = String.Format("{0:C}", prestacao * prazoMeses)

        'mostra o total de juros
        lblJurosTotal.Text = String.Format("{0:C}", totalJuros)



    End Sub

    Private Bitmap As Bitmap


    Private Sub btnPrint_Click(sender As Object, e As EventArgs) Handles btnPrint.Click

        Dim printDialog As New PrintDialog()
        ' Define o documento do PrintPreviewDialog como o PrintDocument
        PrintPreviewDialog1.Document = PrintDocument1

        printDialog.Document = PrintDocument1
        ' Define o zoom do PrintPreviewControl como 1 (100%)
        PrintPreviewDialog1.PrintPreviewControl.Zoom = 1

        ' Configurar as cores do DataGridView
        DataGridView1.AlternatingRowsDefaultCellStyle.BackColor = Color.LightGray  ' Cor de fundo das linhas alternadas
        DataGridView1.DefaultCellStyle.BackColor = Color.White                     ' Cor de fundo das linhas padrão

        PrintDocument1.Print()


    End Sub

    Private Sub PrintDocument1_PrintPage(sender As Object, e As Printing.PrintPageEventArgs) Handles PrintDocument1.PrintPage

        ' Margens e fontes para impressão
        Dim leftMargin As Integer = e.MarginBounds.Left
        Dim topMargin As Integer = e.MarginBounds.Top
        Dim fontTitle As New Font("Arial", 12, FontStyle.Bold)
        Dim fontBody As New Font("Arial", 10)
        Dim currentY As Integer = topMargin

        ' Imprimir título
        e.Graphics.DrawString("Dados sobre Pagamentos", fontTitle, Brushes.Black, leftMargin, currentY)
        currentY += fontTitle.Height + 5

        ' Desenhar cabeçalho das colunas
        Dim headerHeight As Integer = fontBody.Height + 5
        Dim columnX As Integer = leftMargin

        For Each column As DataGridViewColumn In DataGridView1.Columns
            e.Graphics.DrawString(column.HeaderText, fontBody, Brushes.Black, columnX, currentY)
            columnX += column.Width + 10
        Next

        currentY += headerHeight ' Avançar para a próxima linha

        ' Desenhar as linhas do DataGridView
        Dim rowHeight As Integer = fontBody.Height + 5
        Dim morePages As Boolean = False

        While dataGridViewPrintRowIndex < DataGridView1.Rows.Count
            Dim row As DataGridViewRow = DataGridView1.Rows(dataGridViewPrintRowIndex)
            columnX = leftMargin

            For Each cell As DataGridViewCell In row.Cells
                e.Graphics.DrawString(cell.Value?.ToString(), fontBody, Brushes.Black, columnX, currentY)
                columnX += cell.OwningColumn.Width + 10
            Next

            currentY += rowHeight
            dataGridViewPrintRowIndex += 1

            ' Verificar se passou do fim da página
            If currentY + rowHeight > e.MarginBounds.Bottom Then
                morePages = True
                dataGridViewPrintPageNum += 1
                Exit While
            End If
        End While

        e.HasMorePages = morePages



    End Sub


End Class
