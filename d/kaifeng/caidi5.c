inherit ROOM;

void create()
{
        set("short", "�˵�");
        set("long", @LONG
��Ƭ��԰�Ӽ����������һЩʱ���߲ˡ������м���ľ׮
����Ĳ˼��ӣ���һЩ���ٵ��߲��������������Ŀ��ȥ����
���һƬ��԰�ӣ���Ȼ���������û�м��òˡ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"caidi",
  		"east" : __DIR__"kongdi",
  		"south" : __DIR__"maofang",
  		"north" : __DIR__"jiaomen",
	]));

        set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}
