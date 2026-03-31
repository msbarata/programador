<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.txtID = New System.Windows.Forms.TextBox()
        Me.TxtMarca = New System.Windows.Forms.TextBox()
        Me.txtModelo = New System.Windows.Forms.TextBox()
        Me.btnPesquisa = New System.Windows.Forms.Button()
        Me.PictureBox2 = New System.Windows.Forms.PictureBox()
        Me.btnInserir = New System.Windows.Forms.Button()
        Me.btnActualizar = New System.Windows.Forms.Button()
        Me.btnEliminar = New System.Windows.Forms.Button()
        Me.BtnUpload = New System.Windows.Forms.Button()
        Me.DataGridView1 = New System.Windows.Forms.DataGridView()
        Me.StandBindingSource = New System.Windows.Forms.BindingSource(Me.components)
        Me.StandDataSet = New Ex_Stand.StandDataSet()
        Me.OpenFileDialog1 = New System.Windows.Forms.OpenFileDialog()
        Me.StandTableAdapter = New Ex_Stand.StandDataSetTableAdapters.StandTableAdapter()
        Me.TableAdapterManager = New Ex_Stand.StandDataSetTableAdapters.TableAdapterManager()
        Me.IdDataGridViewTextBoxColumn = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.MarcaDataGridViewTextBoxColumn = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.ModeloDataGridViewTextBoxColumn = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.FotoDataGridViewImageColumn = New System.Windows.Forms.DataGridViewImageColumn()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.DataGridView1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.StandBindingSource, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.StandDataSet, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(-4, -1)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(891, 229)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 0
        Me.PictureBox1.TabStop = False
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(53, 278)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(21, 13)
        Me.Label1.TabIndex = 1
        Me.Label1.Text = "ID:"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(53, 332)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(40, 13)
        Me.Label2.TabIndex = 2
        Me.Label2.Text = "Marca:"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(53, 400)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(45, 13)
        Me.Label3.TabIndex = 3
        Me.Label3.Text = "Modelo:"
        '
        'txtID
        '
        Me.txtID.Location = New System.Drawing.Point(98, 278)
        Me.txtID.Name = "txtID"
        Me.txtID.Size = New System.Drawing.Size(80, 20)
        Me.txtID.TabIndex = 4
        '
        'TxtMarca
        '
        Me.TxtMarca.Location = New System.Drawing.Point(100, 332)
        Me.TxtMarca.Name = "TxtMarca"
        Me.TxtMarca.Size = New System.Drawing.Size(215, 20)
        Me.TxtMarca.TabIndex = 5
        '
        'txtModelo
        '
        Me.txtModelo.Location = New System.Drawing.Point(105, 392)
        Me.txtModelo.Name = "txtModelo"
        Me.txtModelo.Size = New System.Drawing.Size(221, 20)
        Me.txtModelo.TabIndex = 6
        '
        'btnPesquisa
        '
        Me.btnPesquisa.Location = New System.Drawing.Point(240, 273)
        Me.btnPesquisa.Name = "btnPesquisa"
        Me.btnPesquisa.Size = New System.Drawing.Size(75, 23)
        Me.btnPesquisa.TabIndex = 7
        Me.btnPesquisa.Text = "Pesquisar"
        Me.btnPesquisa.UseVisualStyleBackColor = True
        '
        'PictureBox2
        '
        Me.PictureBox2.Location = New System.Drawing.Point(358, 243)
        Me.PictureBox2.Name = "PictureBox2"
        Me.PictureBox2.Size = New System.Drawing.Size(294, 200)
        Me.PictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox2.TabIndex = 8
        Me.PictureBox2.TabStop = False
        '
        'btnInserir
        '
        Me.btnInserir.Location = New System.Drawing.Point(716, 259)
        Me.btnInserir.Name = "btnInserir"
        Me.btnInserir.Size = New System.Drawing.Size(108, 23)
        Me.btnInserir.TabIndex = 9
        Me.btnInserir.Text = "Inserir"
        Me.btnInserir.UseVisualStyleBackColor = True
        '
        'btnActualizar
        '
        Me.btnActualizar.Location = New System.Drawing.Point(716, 322)
        Me.btnActualizar.Name = "btnActualizar"
        Me.btnActualizar.Size = New System.Drawing.Size(108, 23)
        Me.btnActualizar.TabIndex = 10
        Me.btnActualizar.Text = "Actualizar"
        Me.btnActualizar.UseVisualStyleBackColor = True
        '
        'btnEliminar
        '
        Me.btnEliminar.Location = New System.Drawing.Point(716, 389)
        Me.btnEliminar.Name = "btnEliminar"
        Me.btnEliminar.Size = New System.Drawing.Size(108, 23)
        Me.btnEliminar.TabIndex = 11
        Me.btnEliminar.Text = "Eliminar"
        Me.btnEliminar.UseVisualStyleBackColor = True
        '
        'BtnUpload
        '
        Me.BtnUpload.Location = New System.Drawing.Point(458, 449)
        Me.BtnUpload.Name = "BtnUpload"
        Me.BtnUpload.Size = New System.Drawing.Size(75, 23)
        Me.BtnUpload.TabIndex = 12
        Me.BtnUpload.Text = "Upload"
        Me.BtnUpload.UseVisualStyleBackColor = True
        '
        'DataGridView1
        '
        Me.DataGridView1.AutoGenerateColumns = False
        Me.DataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize
        Me.DataGridView1.Columns.AddRange(New System.Windows.Forms.DataGridViewColumn() {Me.IdDataGridViewTextBoxColumn, Me.MarcaDataGridViewTextBoxColumn, Me.ModeloDataGridViewTextBoxColumn, Me.FotoDataGridViewImageColumn})
        Me.DataGridView1.DataSource = Me.StandBindingSource
        Me.DataGridView1.Location = New System.Drawing.Point(12, 510)
        Me.DataGridView1.Name = "DataGridView1"
        Me.DataGridView1.Size = New System.Drawing.Size(812, 185)
        Me.DataGridView1.TabIndex = 13
        '
        'StandBindingSource
        '
        Me.StandBindingSource.DataMember = "Stand"
        Me.StandBindingSource.DataSource = Me.StandDataSet
        '
        'StandDataSet
        '
        Me.StandDataSet.DataSetName = "StandDataSet"
        Me.StandDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema
        '
        'OpenFileDialog1
        '
        Me.OpenFileDialog1.FileName = "OpenFileDialog1"
        '
        'StandTableAdapter
        '
        Me.StandTableAdapter.ClearBeforeFill = True
        '
        'TableAdapterManager
        '
        Me.TableAdapterManager.BackupDataSetBeforeUpdate = False
        Me.TableAdapterManager.StandTableAdapter = Me.StandTableAdapter
        Me.TableAdapterManager.UpdateOrder = Ex_Stand.StandDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete
        '
        'IdDataGridViewTextBoxColumn
        '
        Me.IdDataGridViewTextBoxColumn.DataPropertyName = "Id"
        Me.IdDataGridViewTextBoxColumn.HeaderText = "Id"
        Me.IdDataGridViewTextBoxColumn.Name = "IdDataGridViewTextBoxColumn"
        '
        'MarcaDataGridViewTextBoxColumn
        '
        Me.MarcaDataGridViewTextBoxColumn.DataPropertyName = "Marca"
        Me.MarcaDataGridViewTextBoxColumn.HeaderText = "Marca"
        Me.MarcaDataGridViewTextBoxColumn.Name = "MarcaDataGridViewTextBoxColumn"
        '
        'ModeloDataGridViewTextBoxColumn
        '
        Me.ModeloDataGridViewTextBoxColumn.DataPropertyName = "Modelo"
        Me.ModeloDataGridViewTextBoxColumn.HeaderText = "Modelo"
        Me.ModeloDataGridViewTextBoxColumn.Name = "ModeloDataGridViewTextBoxColumn"
        '
        'FotoDataGridViewImageColumn
        '
        Me.FotoDataGridViewImageColumn.DataPropertyName = "Foto"
        Me.FotoDataGridViewImageColumn.HeaderText = "Foto"
        Me.FotoDataGridViewImageColumn.Image = CType(resources.GetObject("FotoDataGridViewImageColumn.Image"), System.Drawing.Image)
        Me.FotoDataGridViewImageColumn.ImageLayout = System.Windows.Forms.DataGridViewImageCellLayout.Stretch
        Me.FotoDataGridViewImageColumn.Name = "FotoDataGridViewImageColumn"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(855, 707)
        Me.Controls.Add(Me.DataGridView1)
        Me.Controls.Add(Me.BtnUpload)
        Me.Controls.Add(Me.btnEliminar)
        Me.Controls.Add(Me.btnActualizar)
        Me.Controls.Add(Me.btnInserir)
        Me.Controls.Add(Me.PictureBox2)
        Me.Controls.Add(Me.btnPesquisa)
        Me.Controls.Add(Me.txtModelo)
        Me.Controls.Add(Me.TxtMarca)
        Me.Controls.Add(Me.txtID)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.PictureBox1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.DataGridView1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.StandBindingSource, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.StandDataSet, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents PictureBox1 As PictureBox
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents txtID As TextBox
    Friend WithEvents TxtMarca As TextBox
    Friend WithEvents txtModelo As TextBox
    Friend WithEvents btnPesquisa As Button
    Friend WithEvents PictureBox2 As PictureBox
    Friend WithEvents btnInserir As Button
    Friend WithEvents btnActualizar As Button
    Friend WithEvents btnEliminar As Button
    Friend WithEvents BtnUpload As Button
    Friend WithEvents DataGridView1 As DataGridView
    Friend WithEvents OpenFileDialog1 As OpenFileDialog
    Friend WithEvents StandDataSet As StandDataSet
    Friend WithEvents StandBindingSource As BindingSource
    Friend WithEvents StandTableAdapter As StandDataSetTableAdapters.StandTableAdapter
    Friend WithEvents TableAdapterManager As StandDataSetTableAdapters.TableAdapterManager
    Friend WithEvents IdDataGridViewTextBoxColumn As DataGridViewTextBoxColumn
    Friend WithEvents MarcaDataGridViewTextBoxColumn As DataGridViewTextBoxColumn
    Friend WithEvents ModeloDataGridViewTextBoxColumn As DataGridViewTextBoxColumn
    Friend WithEvents FotoDataGridViewImageColumn As DataGridViewImageColumn
End Class
