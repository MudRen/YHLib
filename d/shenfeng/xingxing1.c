inherit ROOM;

void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
Զ��������һĨ���͡�ת��֮�䣬ʯ��Խ��Խ����һ����
����ֱ���ȥ��ɽʯ�����힅�����ƺ����б�����أ����߽�
ʱ�����ͱ��м�¶��һ����������ɽ��ֱ�߽�ȥ�����Ǹ����
�ؽ�֮��Ľ�ͨ�׵�����Ͽ��
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
  		"west" : __DIR__"xingxing2",
  		"east" : __DIR__"guandao4",
	]));
        set("objects", ([
                __DIR__"npc/seller" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
