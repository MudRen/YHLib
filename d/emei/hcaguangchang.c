inherit ROOM;

void create()
{
      set("short","�����ֹ㳡");
      set("long",@LONG
�����Ƕ��һ����ֵĹ㳡������������ש����ǰ����һ��
̨�ף�ͨ�����۱����ǰ�и�����ߵĴ���¯����¯ǰ����
̨�ϣ�������գ�����Ʈ�ơ��㳡�ϼ���Сʦ̫������������
�����Ҹ���һ������ͨ���
LONG);
      	set("objects", ([
           	CLASS_D("emei") + "/xu" : 1,
      	]));

      	set("outdoors", "emei");

      	set("exits", ([
          	"north" : __DIR__"hcazhengdian", 
          	"south" : __DIR__"hcadadian", 
          	"west"  : __DIR__"hcawest1", 
          	"east"  : __DIR__"hcaeast1", 
      	]));

      	set("valid_startroom", 1);

      	setup();
      	replace_program(ROOM);
      	"/clone/board/emei_b"->foo();
}
