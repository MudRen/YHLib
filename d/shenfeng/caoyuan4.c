inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�˴��������Į������ط���Ȼ��ͬ����ػ�ɳ�л��Ŵ�
��ʯ�������ִ������������ף�·ʮ�ֵ�������С�
LONG);
        set("outdoors", "xiyu");
        set("exits", ([
  		"west" : __DIR__"caoyuan5",
  		"east" : __DIR__"caoyuan3",
	]));

	setup();
	replace_program(ROOM);
}
