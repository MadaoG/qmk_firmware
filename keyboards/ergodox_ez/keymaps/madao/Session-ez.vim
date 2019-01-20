let SessionLoad = 1
if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <silent> <expr> <BS> lexima#expand('<BS>', 'i')
imap <S-Tab> <Plug>SuperTabBackward
inoremap <silent> <C-Tab> =UltiSnips#ListSnippets()
nnoremap <silent> <expr>  &ma?":w:e#":":e#"
snoremap <silent>  c
nnoremap <silent>  :call TmuxOrSplitSwitch('h', 'L')
xnoremap <silent> 	 :call UltiSnips#SaveLastVisualSelection()gvs
snoremap <silent> 	 :call UltiSnips#ExpandSnippet()
nnoremap 	 :g//#<Left><Left>
nnoremap <silent> <NL> :call TmuxOrSplitSwitch('j', 'D')
nnoremap <silent>  :call TmuxOrSplitSwitch('k', 'U')
nnoremap <silent>  :call TmuxOrSplitSwitch('l', 'R')
nnoremap  :
xnoremap  :
nmap  <Plug>(RepeatRedo)
snoremap  "_c
nnoremap <silent>  tp :set invpaste paste?
nnoremap <silent>  tw :set wrap!
nnoremap <silent>  tt :TagbarToggle
nnoremap <silent>  tl :set relativenumber!
nnoremap <silent>  gw :Gwrite
nnoremap <silent>  gu :GitGutterUndoHunk
nnoremap <silent>  gt :Gcommit -v -q %:pzRi
nnoremap <silent>  gs :Gstatus
nnoremap <silent>  gr :Gread
nnoremap <silent>  gp :Ggrep 
nnoremap <silent>  go :Git checkout 
nnoremap <silent>  gn :GitGutterNextHunk
nnoremap <silent>  gm :Gmove 
nnoremap <silent>  gl :silent! Glog:bot copen
nnoremap <silent>  gh :GitGutterStageHunk
nnoremap <silent>  gg :GitGutterStageHunk  :Gcommit -v -q zRi
nnoremap <silent>  ge :Gedit
nnoremap <silent>  gd :Gdiff
nnoremap <silent>  gc :Gcommit -v -qzRi
nnoremap <silent>  gb :Git branch 
nnoremap <silent>  ga :Git add %:p
xnoremap  / y/"
xnoremap  r y:%s/0//g<Left><Left>
nmap  m :marks
nnoremap  D :dlist /
nnoremap  d :djump /
nnoremap <silent>  W :%s/\s\+$//e
nnoremap <silent>  R yiwq:i%s/\<0\>/0/hF/l
nnoremap <silent>  i :let @/ = '\<' . expand('<cword>') . '\>' | set hlsearchcgn
nnoremap <expr>  q &ma?":wq":":q"
nnoremap <silent>  w :w
nnoremap <silent>  V :source $MYVIMRC
nnoremap <silent>  v :tabedit $MYVIMRC
nnoremap  r :%smagic/\<\>/
nnoremap <silent>  o :nohlsearch
nnoremap <silent>  a @="@a"
nnoremap  , mz:%smagic//g |norm `z<Left><Left><Left><Left><Left><Left><Left><Left><Left><Left><Left>
nnoremap  . :smagic//g<Left><Left>
nnoremap <silent>  z :wa|exe "mksession! " . v:this_session :qa
nnoremap <silent>  e :w:e 
nnoremap <silent>  b :ls:b 
nnoremap    :s//g<Left><Left>
nnoremap <silent> * :let @/ = '\<' . expand('<cword>') . '\>' | set hlsearch
nmap . <Plug>(RepeatDot)
nnoremap / /\v
xnoremap / /\v
nnoremap ? ?\v
xnoremap ? ?\v
nnoremap <silent> Q @="@q"
xmap S <Plug>VSurround
nmap U <Plug>(RepeatUndoLine)
nnoremap <silent> Y y$
xmap [% [%m'gv``
xmap ]% ]%m'gv``
xnoremap a% :normal! F%vf%
omap ay <Plug>(textobj-syntax-a)
xmap ay <Plug>(textobj-syntax-a)
onoremap <silent> a  :call textobj#space#a()
xnoremap <silent> a  :call textobj#space#a()
onoremap <silent> ai :call textobj#indentation#a()
xnoremap <silent> ai :call textobj#indentation#a()
onoremap <silent> al :normal! $v0
xnoremap <silent> al :normal! $v0
onoremap <silent> an :call textobj#number#a()
xnoremap <silent> an :call textobj#number#a()
onoremap a# :normal va#
xnoremap a# :normal! F#vf#
onoremap a- :normal va-
xnoremap a- :normal! F-vf-
onoremap a% :normal va%
onoremap a+ :normal va+
xnoremap a+ :normal! F+vf+
onoremap a* :normal va*
xnoremap a* :normal! F*vf*
onoremap a\ :normal va\
xnoremap a\ :normal! F\vf\
onoremap a/ :normal va/
xnoremap a/ :normal! F/vf/
onoremap a| :normal va|
xnoremap a| :normal! F|vf|
onoremap a; :normal va;
xnoremap a; :normal! F;vf;
onoremap a, :normal va,
xnoremap a, :normal! F,vf,
onoremap a: :normal va:
xnoremap a: :normal! F:vf:
onoremap a. :normal va.
xnoremap a. :normal! F.vf.
onoremap a_ :normal va_
xnoremap a_ :normal! F_vf_
omap aa <Plug>SidewaysArgumentTextobjA
xmap aa <Plug>SidewaysArgumentTextobjA
nmap cS <Plug>CSurround
nmap cs <Plug>Csurround
nnoremap <silent> cp yap<S-}>p
nmap ds <Plug>Dsurround
nnoremap <silent> dc :call utils#deletebrackets()
xmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
nnoremap <silent> gs :Switch
nmap gcu <Plug>Commentary<Plug>Commentary
nmap gcc <Plug>CommentaryLine
omap gc <Plug>Commentary
nmap gc <Plug>Commentary
xmap gc <Plug>Commentary
xmap gS <Plug>VgSurround
nnoremap <silent> g. :set opfunc=utils#wrapg@
nnoremap gl :normal! 
nmap ga <Plug>(EasyAlign)
xnoremap gl :normal! 
xmap ga <Plug>(EasyAlign)
omap iy <Plug>(textobj-syntax-i)
xmap iy <Plug>(textobj-syntax-i)
onoremap <silent> i  :call textobj#space#i()
xnoremap <silent> i  :call textobj#space#i()
onoremap <silent> ii :call textobj#indentation#i()
xnoremap <silent> ii :call textobj#indentation#i()
onoremap <silent> il :normal! g_v^
xnoremap <silent> il :normal! g_v^
onoremap <silent> ie :normal! GVgg
xnoremap <silent> ie :normal! G$Vgg0
onoremap <silent> in :call textobj#number#i()
xnoremap <silent> in :call textobj#number#i()
onoremap i# :normal vi#
xnoremap i# :normal! T#vt#
onoremap i- :normal vi-
xnoremap i- :normal! T-vt-
onoremap i% :normal vi%
xnoremap i% :normal! T%vt%
onoremap i+ :normal vi+
xnoremap i+ :normal! T+vt+
onoremap i* :normal vi*
xnoremap i* :normal! T*vt*
onoremap i\ :normal vi\
xnoremap i\ :normal! T\vt\
onoremap i/ :normal vi/
xnoremap i/ :normal! T/vt/
onoremap i| :normal vi|
xnoremap i| :normal! T|vt|
onoremap i; :normal vi;
xnoremap i; :normal! T;vt;
onoremap i, :normal vi,
xnoremap i, :normal! T,vt,
onoremap i: :normal vi:
xnoremap i: :normal! T:vt:
onoremap i. :normal vi.
xnoremap i. :normal! T.vt.
onoremap i_ :normal vi_
xnoremap i_ :normal! T_vt_
omap ia <Plug>SidewaysArgumentTextobjI
xmap ia <Plug>SidewaysArgumentTextobjI
nnoremap <silent> m, :SidewaysRight
nnoremap <silent> m. :SidewaysLeft
nmap u <Plug>(RepeatUndo)
nmap ySS <Plug>YSsurround
nmap ySs <Plug>YSsurround
nmap yss <Plug>Yssurround
nmap yS <Plug>YSurround
nmap ys <Plug>Ysurround
nnoremap <silent> yp yyp
nnoremap <SNR>57_: :=v:count ? v:count : ''
nnoremap <SNR>55_: :=v:count ? v:count : ''
nnoremap <silent> <Plug>(RepeatDot) :exe repeat#run(v:count)
nnoremap <silent> <Plug>(RepeatUndo) :call repeat#wrap('u',v:count)
nnoremap <silent> <Plug>(RepeatUndoLine) :call repeat#wrap('U',v:count)
nnoremap <silent> <Plug>(RepeatRedo) :call repeat#wrap("\<C-R>",v:count)
nnoremap <SNR>58_: :=v:count ? v:count : ''
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
nnoremap <silent> <Plug>GitGutterPreviewHunk :GitGutterPreviewHunk
nnoremap <silent> <Plug>GitGutterUndoHunk :GitGutterUndoHunk
nnoremap <silent> <Plug>GitGutterStageHunk :GitGutterStageHunk
nnoremap <silent> <expr> <Plug>GitGutterPrevHunk &diff ? '[c' : ":\execute v:count1 . 'GitGutterPrevHunk'\"
nnoremap <silent> <expr> <Plug>GitGutterNextHunk &diff ? ']c' : ":\execute v:count1 . 'GitGutterNextHunk'\"
xnoremap <silent> <Plug>GitGutterTextObjectOuterVisual :call gitgutter#hunk#text_object(0)
xnoremap <silent> <Plug>GitGutterTextObjectInnerVisual :call gitgutter#hunk#text_object(1)
onoremap <silent> <Plug>GitGutterTextObjectOuterPending :call gitgutter#hunk#text_object(0)
onoremap <silent> <Plug>GitGutterTextObjectInnerPending :call gitgutter#hunk#text_object(1)
snoremap <silent> <Del> c
snoremap <silent> <BS> c
snoremap <silent> <C-Tab> :call UltiSnips#ListSnippets()
nmap <silent> <Plug>CommentaryUndo :echoerr "Change your <Plug>CommentaryUndo map to <Plug>Commentary<Plug>Commentary"
nnoremap <silent> <Plug>SurroundRepeat .
xnoremap <Plug>SidewaysArgumentTextobjI :call sideways#textobj#Argument('i')
onoremap <Plug>SidewaysArgumentTextobjI :call sideways#textobj#Argument('i')
xnoremap <Plug>SidewaysArgumentTextobjA :call sideways#textobj#Argument('a')
onoremap <Plug>SidewaysArgumentTextobjA :call sideways#textobj#Argument('a')
nnoremap <silent> <Plug>SidewaysRight :SidewaysRight
nnoremap <silent> <Plug>SidewaysLeft :SidewaysLeft
imap S <Plug>ISurround
imap s <Plug>Isurround
inoremap <silent> 	 =UltiSnips#ExpandSnippet()
inoremap <silent> <expr>  lexima#expand('<CR>', 'i')
cnoremap <expr>  utils#ccr()
imap  <Plug>Isurround
inoremap  
inoremap <silent> <expr>   lexima#expand('<SPACE>', 'i')
inoremap <silent> <expr> " lexima#expand('"', 'i')
inoremap <silent> <expr> ' lexima#expand('''', 'i')
inoremap <silent> <expr> ( lexima#expand('(', 'i')
inoremap <silent> <expr> ) lexima#expand(')', 'i')
inoremap <silent> <expr> [ lexima#expand('[', 'i')
inoremap <silent> <expr> ] lexima#expand(']', 'i')
inoremap <silent> <expr> ` lexima#expand('`', 'i')
inoremap <silent> <expr> { lexima#expand('{', 'i')
inoremap <silent> <expr> } lexima#expand('}', 'i')
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set background=dark
set backspace=indent,eol,start
set define=^[nvsxoilct]\\?\\(nore\\)\\?map\\s\\+\\(<[a-zA-Z]*>\\s*\\)*
set diffopt=filler,vertical
set encoding=utf-8
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set formatoptions=cqrn1j
set history=1000
set hlsearch
set ignorecase
set incsearch
set laststatus=2
set lazyredraw
set listchars=tab:â–¸.,eol:Â¬,trail:â€¢,nbsp:~
set nomodeline
set nomore
set operatorfunc=<SNR>22_go
set path=.,,
set printoptions=paper:a4
set pumheight=8
set ruler
set runtimepath=~/.vim,~/.vim/plugged/vim-matchit/,~/.vim/plugged/vim-easy-align/,~/.vim/plugged/completor.vim/,~/.vim/plugged/sideways.vim/,~/.vim/plugged/vimux/,~/.vim/plugged/vim-surround/,~/.vim/plugged/vim-fugitive/,~/.vim/plugged/asyncrun.vim/,~/.vim/plugged/gruvbox/,~/.vim/plugged/vim-commentary/,~/.vim/plugged/vim-repeat/,~/.vim/plugged/vim-textobj-user/,~/.vim/plugged/vim-textobj-python/,~/.vim/plugged/vim-textobj-syntax/,~/.vim/plugged/Join/,~/.vim/plugged/switch.vim/,~/.vim/plugged/lexima.vim/,~/.vim/plugged/usr/,~/.vim/plugged/vim-eunuch/,~/.vim/plugged/supertab/,~/.vim/plugged/ultisnips/,~/.vim/plugged/vimtex/,~/.vim/plugged/vim-gitgutter/,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim81,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/snip_source/,~/.vim/plugged/vim-textobj-python/after,~/.vim/plugged/ultisnips/after,~/.vim/plugged/vimtex/after,~/.vim/after
set scrolloff=1
set shiftwidth=4
set showbreak=>\ 
set softtabstop=4
set splitright
set statusline=\ %t\ |\ %{expand('%:~:h')}/\ %{WrapElement('g')}%M%{(&paste)?'\ paste\ ':''}%=\ %l:%c\ /\ %L\ |\ %p%%\ 
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set suffixesadd=.vim
set noswapfile
set tabstop=4
set textwidth=78
set tildeop
set undofile
set viminfo='1000,<1000,s100,:0
set virtualedit=block
set wildmenu
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/repositories/qmk_firmware/keyboards/ergodox_ez/keymaps/madao
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +27 todo.md
badd +42 config.h
badd +82 gauss.h
badd +266 layer_template.c
badd +45 macro_functions.h
badd +184 mappings.h
badd +1 rules.mk
badd +1 special_characters.txt
badd +11 tap_functions.h
badd +518 ~/repositories/qmk_firmware/Makefile
badd +115 ~/repositories/qmk_firmware/quantum/keymap_extras/keymap_german.h
badd +18 ~/.vimrc
badd +1094 ~/.notes/vimtips.txt
badd +378 keymap.c
badd +1 Compiling:\ keyboards/ergodox_ez/keymaps/madao/keymap.c\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ In\ file\ included\ from\ \[01m\[Kkeyboards/ergodox_ez/keymaps/madao/keymap.c
badd +1 Compiling:\ keyboards/ergodox_ez/keymaps/madao/keymap.c\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ In\ file\ included\ from\ \[01m\[Kquantum/quantum.h
badd +1 Session-ez.vim
badd +0 en.log
argglobal
silent! argdel *
$argadd todo.md
$argadd config.h
$argadd gauss.h
$argadd todo.md
$argadd layer_template.c
$argadd macro_functions.h
$argadd mappings.h
$argadd rules.mk
$argadd special_characters.txt
$argadd tap_functions.h
$argadd todo.md
edit keymap.c
set splitbelow splitright
set nosplitbelow
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
argglobal
if bufexists('keymap.c') | buffer keymap.c | else | edit keymap.c | endif
inoremap <buffer> <nowait> <silent>  =lexima#insmode#escape()
setlocal keymap=
setlocal noarabic
setlocal autoindent
setlocal backupcopy=
setlocal balloonexpr=
setlocal nobinary
setlocal nobreakindent
setlocal breakindentopt=
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
set colorcolumn=+1
setlocal colorcolumn=+1
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=//\ %s
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
set cursorline
setlocal cursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal expandtab
if &filetype != 'c'
setlocal filetype=c
endif
setlocal fixendofline
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldmarker={{{,}}}
setlocal foldmethod=manual
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=n1jcroql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal formatprg=
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=-1
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
set linebreak
setlocal linebreak
setlocal nolisp
setlocal lispwords=
set list
setlocal list
setlocal makeencoding=
setlocal makeprg=make\ ergodox_ez:madao
setlocal matchpairs=(:),{:},[:]
setlocal nomodeline
setlocal modifiable
setlocal nrformats=bin,octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=ccomplete#Complete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
set relativenumber
setlocal relativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal shiftwidth=4
setlocal noshortname
setlocal signcolumn=auto
setlocal nosmartindent
setlocal softtabstop=4
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=
setlocal suffixesadd=.vim
setlocal noswapfile
setlocal synmaxcol=3000
if &syntax != 'c'
setlocal syntax=c
endif
setlocal tabstop=4
setlocal tagcase=
setlocal tags=~/repositories/qmk_firmware/.git/tags,./tags,./TAGS,tags,TAGS
setlocal termwinkey=
setlocal termwinscroll=10000
setlocal termwinsize=
setlocal textwidth=78
setlocal thesaurus=
setlocal undofile
setlocal undolevels=-123456
setlocal varsofttabstop=
setlocal vartabstop=
setlocal nowinfixheight
setlocal nowinfixwidth
set nowrap
setlocal nowrap
setlocal wrapmargin=0
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
set winminheight=1 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
