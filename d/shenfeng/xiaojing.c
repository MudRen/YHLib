inherit ROOM;
void create()
{
	set("short", "ʯ��С��");
	set("long", @LONG
�˴��������Į������ط���Ȼ��ͬ����ػ�ɳ�л��Ŵ�
��ʯ�������ִ������������ף�ɽ�����ƴ��ֿɼ���·����ʮ
�ֵ�������С�
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
		"east" : __DIR__"lvzhou",
		"north" : __DIR__"bridge1",
	]));

	setup();
	replace_program(ROOM);
}
