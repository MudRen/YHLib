inherit ROOM;

void create()
{
  	set ("short", "�ӻ���");
  	set ("long", @LONG
���������ݳ�����һ���ӻ��̣���Ȼ���ڵĶ������٣���
��Ϊ�ش��ıȽ�ƫƧ����������Ҳ���������塣
LONG);

  	set("exits", ([  
    		"south" : __DIR__"yanling1",
 
	]));
        set("objects" , ([
                __DIR__"npc/zhaolaoban" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
