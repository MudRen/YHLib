inherit ROOM;

void create()
{
      	set("short", "���϶���");
      	set("long", @LONG
���϶����ɷ����⡣��˵Զ��ʱ���о�λ����ס�����
�����֪�������ں��꣬���ں��ꡣ��ԯ�ʵ۷õ��ڴˣ���
һ���ţ���Ի�����º�����Ի�����ˡ����Ǿ��϶�����������
��������������˽�ȥ��ֻ��Щ��վ�ڶ���̸Ц���С�����
��������ʮ�ŵ��յ�ǧ���֣�һ·�򱱵�����ʯ��
LONG);
      	set("objects", ([
           	"/clone/quarry/hou" : 2,
      	]));
      	set("outdoors", "emei");
      	set("exits", ([
          	"east"      : __DIR__"jsjdg4",
          	"enter"     : __DIR__"jiulaodong",
          	"northwest" : __DIR__"lianhuashi",
      	]));
      	setup();
        replace_program(ROOM);
}
