inherit ROOM;

void create()
{
        set("short", "�ٵ�" );
        set("long", @LONG
������һ����ٵ��ϣ����Բ�ʱ���˴�������߹�������
�ֱ���м����ǽ������ˡ�������Լ���Կ������ݣ����ߺ�һ
��С·������
LONG);
        set("outdoors", "jingzhou");
        set("exits", ([
  		"east" : __DIR__"guandao1",
  		"west" : __DIR__"guandao3",
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

