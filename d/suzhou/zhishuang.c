inherit ROOM;

void create()
{
	set("short", "��ˬ��");
	set("long", @LONG
��ǧ��ʯ���������ˬ�������������ڻ�����������
�棬��ɽ�ϵ���ߵ㡣����ȡ����ɽˬ������Ϧ������֮�⡣
�ɳơ�С��̨�����Ǻ�ӿ�嶥������ƽ̨�����������Ұ��Զ
��Ⱥ�����ƣ������������硰ʨ�ӻ�ͷ������һ�������＾
�ڹ۳�Ⱥ����Ĳ�ӥ��εΪ׳�ۡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
                "north" : __DIR__"shijianshi",
		"south" : __DIR__"qianrenshi",
	]));
	set("objects", ([
		__DIR__"npc/lady1" :1,
	]));
	setup();
	replace_program(ROOM);
}

