inherit ROOM;

void create()
{
	set("short","ˮ������");
	set("long", @LONG
����һƬ��ڣ�ʲô����������ֻ����ˮ�ε�������
LONG);
	set("exits",([
	       "east" :__DIR__"inhole2",           
	]));
	
	set("objects",([
	       "/clone/beast/yanjingshe" : 1,
	]));
	
	setup();

}

void init()
{
       	object me = this_player();

       	if (present("fire", me))
       	{
       		set("long", @LONG
Խ�������ߵ�·Խ����խ������Ҳ��һ˿����Ҳ�䲻������
���û�л��۵Ļ��������Ǵ粽���С���֪������·��ͨ��ʲ
ô�ط�����ֻ������������ɪɪ�����ɵش��˸�������
LONG);
       		set("exits/west",__DIR__"zigai4",);
       	}
       	return ;
}

