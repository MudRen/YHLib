inherit ROOM;
void create()
{
	set("short", "�����");
        set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ
�Ҵң�����˶����ϱ���ȥ��������һ�����ֵĹ㳡��������
һ��������¡�Ŀ�ջ�����Ը��ص����ǽ�����������˵Ҳ����
���ǵ��Ļ�ص㡣������һ��Ǯׯ�������������������Ľ���
������
LONG );
        set("outdoors", "city");
	set("objects", ([
		CLASS_D("ouyang") + "/ouyangke" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west"  : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
	]));
	setup();
        replace_program(ROOM);
}
