inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������������ҵĸ�ۡ��������������޵���Ԫ�Ե�������
�˲�֪�����˲�����ֻ���⸮ۡ����ߴ������Ĵ��ţ�����������ͭ
�������þ���ѩ��������׳�������ڴ������̺�һ�����ţ�ֻ��������
��һ�������ң�д�š�������Ϊ���ĸ����֣���������Ǻ���ʡ��Ѳ��
ĳ�ˡ�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"north" : __DIR__"wroad3",
	]));
        set("objects", ([
                "/d/zhongzhou/npc/jiading" : 2,
        ]));
	setup();
	replace_program(ROOM);
}
