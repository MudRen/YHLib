inherit ROOM;

void create()
{
  	set("short","����");
  	set("long", @LONG
��������������������ڵĳ��ȡ�ֻ���������߸�վ����
ʮ�������֣�����ɭ�ϣ�͸������ɱ����
LONG);

	set("exits",([
        	"north" : __DIR__"dating3",
        	"south" : __DIR__"chlang2",
	]));
  	set("objects",([
     		__DIR__"npc/dizi5" : 2,
  	]));
  	setup();
  	replace_program(ROOM);
}
