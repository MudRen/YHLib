inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������й��ź����ҵ۸߿�������
��ȴû�ù����ν "��������" �İ����ɡ�����������ı�
�������ȵ��ܺ�Ӣ��ͬ�룬���˲�ʤ���ꡣ�������������Ƶ�
���佫�Ⱥͽ���Ϊ�׵��ĳ��ȡ�
LONG);
	set("exits", ([
		"south"   : __DIR__"wuhoucigate",
		"northup" : __DIR__"wuhouci",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
