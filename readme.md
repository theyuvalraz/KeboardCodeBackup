
echo 'PATH="$HOME/.local/bin:$PATH"' >> $HOME/.bashrc && source $HOME/.bashrc

qmk flash -kb preonic/rev3_drop -km dragon_yraz 

