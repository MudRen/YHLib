inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ź�������ݵ��˺�֮�ϣ�����������������������
Ϊ���š���������������������������ű��г����С��ߺ�ȡ�
�����ţ��������������ַǷ������������ڱ̲�֮�ϣ���Ӧ��
�ԣ�����ཿ���������������µ�һ������֮�ء�
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"north"     : __DIR__"zhongxin",
		"south"     : __DIR__"nandajie1",
	]));
	set("objects", ([
		__DIR__"npc/seller": 1,
		"/adm/npc/jiaoshi" : 1,
	]));
	setup();
	replace_program(ROOM);
}

