setenv HISTSIZE 1000
setenv EDITOR emacs
set history=2000
set savehist=40

setenv LS_COLORS 'no=00:fi=00:di=01;34:ln=01;36:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;35;01:su=37;41:sg=30;43:tw=30;42\
:ow=34;42:st=37;44:ex=01;31:*.tar=01;35:*.tgz=01;35:*.arj=01;35:*.taz=01;35:*.lzh=01;35:*.zip=01;35:*.z=01;35:*.Z=01;35:*.gz=01;35:*.bz2=\
01;35:*.deb=01;35:*.rpm=01;35:*.jar=01;35:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;3\
5:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.avi=01;35:*.fli=01;35:*.gl=01;35:*.\
dl=01;35:*.xcf=01;35:*.xwd=01;35:*.flac=01;35:*.mp3=01;35:*.mpc=01;35:*.ogg=01;35:*.wav=01;35:'

alias s         'source'
alias e         'emacs'
alias rm        'rm -i'
alias cp        'cp -i -p'
alias mv        'mv -i'
alias ls        'ls --color -p'
alias ll        'ls -ltr'
alias ps        'ps -e'
alias rsh       'rsh -X'
alias less      'less -X'

if ( $?PATH ) then
	setenv PATH /usr/local/browndeer/bin:${PATH}
else
	setenv PATH /usr/local/browndeer/bin
endif

if ( $?LD_LIBRARY_PATH ) then
	setenv LD_LIBRARY_PATH /usr/local/browndeer/lib:${LD_LIBRARY_PATH}
else
	setenv LD_LIBRARY_PATH /usr/local/browndeer/lib
endif

setenv EPIPHANY_HOME      /opt/adapteva/esdk
source ${EPIPHANY_HOME}/setup.csh
