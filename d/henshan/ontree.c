#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�㼫ĿԶ�������ܾ��������ͱڡ�һ������(teng)�Ӹߴ�
���¡���Ȼ���㿴��ǰ���ͱ����ƺ���һ��ɽ��(hole)������
������Զȴ����ôҲ����ȥ��
LONG);
        set("exits", ([ 
               "down" : __DIR__"xuanyadi",
               "up"   : __DIR__"ontree2"
           ]));

	set("item_desc", ([
               "hole"    : HIC "\n̫Զ�ˣ����ò�̫���������������취��ȥ��\n"	NOR,
           
	       "teng"    : YEL"\n��Щ���ٿ������ܽ�ʵ���ƺ��Ǵ������������ġ�\n" NOR,
	]));


	setup();
        replace_program(ROOM);
}