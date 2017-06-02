FROM vincross/xcompile
RUN apt-get update && apt-get install -y default-jre
RUN wget https://github.com/tedostrem/Fast-RTPS/releases/download/1.4.0-1-ga8d009f-1/fastrtps_1.4.0-1-ga8d009f-1_armhf.deb
RUN dpkg -i fastrtps_1.4.0-1-ga8d009f-1_armhf.deb
RUN wget https://github.com/tedostrem/Fast-CDR/releases/download/1.4.0-1-gbf2f013-1/fastcdr_1.4.0-1-gbf2f013-1_armhf.deb
RUN dpkg -i fastcdr_1.4.0-1-gbf2f013-1_armhf.deb
ADD . /gofastrtps
WORKDIR /gofastrtps
