inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ǰ���ɽׯ�㳡���ߵ�һ��С·��Ѱ������ƽʱ����
��������С·��ɽ��
LONG);
  	set("exits", ([
      		"north" : __DIR__"shulin",
      		"south" : __DIR__"shanlu",
     	]));
  	set("outdoors", "baituo");
  	set("objects", ([
      		__DIR__"npc/qiaofu" : 1 ,
      	]));
  	setup();
  	replace_program(ROOM);
}
