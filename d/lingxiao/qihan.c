inherit ROOM;
#include <ansi.h> 

void create()
{
        set("short","������");
        set("long",@LONG
�����������Ǵ���Ӱ��򽣼�����˵�ס����ǽ�Ϲ���һ��
���ã����顰�������������ʷ�������������ּ������Ϸ���
һ��������ƣ��������磬һλ��òӢ���������������ԣ�����
���Եõ��޼����ϵ�һ��÷����
LONG);
        set("exits",([
            	"east"  : __DIR__"houyuan2", 
        ]));
        set("objects", ([
                CLASS_D("lingxiao") + "/baiwanjian" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

