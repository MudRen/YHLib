#include <ansi.h>

int give_gift();

inherit F_CLEAN_UP;

static mixed *story = ({
        "������˵�������ڳ�����һ���������˼�ʮ����������������",
        "�ŷɣ�������Ȼ���ҳ��˴�Ԫ���������Ǹ�ʤ������",
        "�����������治�����ܻ���û�У�",
        "�ŷ���������һ�Ű׻���Ԫ�����������⻹�����ء�",
        "���𣺺ٺ٣�",
        "�ŷɣ��ޣ����磬�м�����˵�ˣ���˵�����Ժ��˵���ɫ��䡣",
        "������ô�䣿",
        "�ŷɣ����ң�����������£����෴�ķ�����",
        "���𣺿������Ҳ���Ҫ��������ˣ�",
        "�ŷɣ�Ӧ�á�",
        "����ݺݵİѴ�Ԫ�����˳�ȥ��",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        STORY_D->give_gift("/clone/fam/gift/str2", 1,
                           HIM "\n��ž����һ��һ���ɵ���������ǰ��\n\n" NOR);
        return 0;
}
