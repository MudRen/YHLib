inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
�˴��Ǹ���·��������Զ�ǿ��⣬�����ɵ����ݣ�����ͨ
��������ɽ����������˳������·��ɽ��ȥ��
LONG);
        set("exits", ([
  		"west" : "/d/kaifeng/tokaifeng",
  		"east" : __DIR__"wroad2",
	]));
        set("outdoors", "zhongzhou");

        setup();
        replace_program(ROOM);
}
