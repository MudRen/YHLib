inherit ROOM;

void create()
{
  	set ("short", "��¥����");
  	set ("long", @LONG
һ���ϳ�¥�����������һ��Ƭ�Ŀ����ؾ����۵ף�Ҫ��
�����ﲼ�������Ҫ����˭�빥��������ֱ�ȵ��컹�ѡ�
LONG);

	set("outdoors", "zhongzhou");

  	set("exits", ([  
    		"down" : __DIR__"chenglou",
 
	]));

        setup();
        replace_program(ROOM);
}
