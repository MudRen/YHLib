inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��������ԭ������ıؾ�֮·�������������ҶӶ�һ��Ҫ
�����ﾭ�����γ�������Ļ���·�ݡ���������Կ���һ����
�ɵĳ��ǣ���������б����ں���ĺۼ�������һ��С�ꡣ
���ſ�ջ��ľ�����ƹ�������ں�����ҡҷ��
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
  		"west" : __DIR__"guandao3",
  		"north" : __DIR__"longmen",
  		"east" : __DIR__"guandao1",
	]));
	setup();
	replace_program(ROOM);
}
