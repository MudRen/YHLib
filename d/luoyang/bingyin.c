inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�����
�еĶ������������е����š�����������Ϣ����ǽ��������˧��������ɫ
��Ѱ�������ܡ����������������ȫ�������Χ�˹��������ƿ�����̫�
������һ�������⡣
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"north" : __DIR__"bingqiku",
  		"south" : __DIR__"bingyindamen",
	]));
        set("objects", ([
                "/d/kaifeng/npc/guanbing" : 4,
                "/d/city/npc/wujiang" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
